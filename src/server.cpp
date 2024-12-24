#include <stdio.h>
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include "llama.h"
#include "llm_request.pb.h"
#include <memory>
#include <grpcpp/grpcpp.h>
#include "llm_request.grpc.pb.h"
#include "RecordRequests.h"
#include "APIKeyEnforcer.h"
#include <toml++/toml.hpp>

#define DEBUG_MODE      false

using namespace std;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using llm_request::AskLLMQuestion;
using llm_request::LLMInit;
using llm_request::LLMInference;


// function definitions
static APIKeyEnforcerBase* loadConfigKeyEnforcer(std::string config_path);
static RecordRequestsBase* loadConfigRecordRequests(std::string config_path);
static void writeConfigKeyEnforcer(std::string config_path, APIKeyEnforcerBase* ke);
static std::string loadConfigModelPath(std::string config_path);
static int loadConfigNPredict(std::string config_path);
void RunServer();

// Service implementation
class AskLLMQuestionServiceImpl final : public AskLLMQuestion::Service {
private:
    RecordRequestsBase *rr;
    APIKeyEnforcerBase *ke;
    llama_model * model;
    llama_model_params model_params;
    int n_predict;

public:
    AskLLMQuestionServiceImpl(RecordRequestsBase *rr_ptr, APIKeyEnforcerBase *ke_ptr, std::string model_path, int n_predict) 
        : rr(rr_ptr), ke(ke_ptr), n_predict(n_predict)
{
        // llama.cpp loading
        model_params = llama_model_default_params();
        model_params.n_gpu_layers = 24;

        model = llama_load_model_from_file(model_path.c_str(), model_params);

        if (model == NULL) {
            fprintf(stderr , "%s: error: unable to load model\n" , __func__);
        }

    }

    ~AskLLMQuestionServiceImpl() {
        llama_free_model(model);

        // save any new keys to the toml file
        writeConfigKeyEnforcer("../config/config.toml", ke);
    }


    // Implementation of the PromptLLM RPC
    Status PromptLLM(ServerContext* context, const LLMInit* request, LLMInference* reply) override {

        // Access the fields in the request
        std::string api_key = request->apikey();
        std::string prompt = request->prompt();
        std::string generated_output = "";

        // initialize threads
        std::promise<bool> verificationPromise;
        std::future<bool> verificationFuture = verificationPromise.get_future();

        std::thread verificationThread([&verificationPromise, ke = this->ke, api_key]() {
            try {
                bool result = ke->KeyVerify(api_key);
                verificationPromise.set_value(result);
            } catch (...) {
                verificationPromise.set_exception(std::current_exception()); // Handle any exceptions
            }
        });


        /**************  llama.cpp; Consider making separate function  ******************/
        // tokenize the prompt
        // find the number of tokens in the prompt
        const int n_prompt = -llama_tokenize(model, prompt.c_str(), prompt.size(), NULL, 0, true, true);
        if (n_prompt < 0) {
            fprintf(stderr, "Error tokenizing prompt, n_prompt = %d\n", n_prompt);
            return Status::CANCELLED;
        }

        // allocate space for the tokens and tokenize the prompt
        std::vector<llama_token> prompt_tokens(n_prompt);
        if (llama_tokenize(model, prompt.c_str(), prompt.size(), prompt_tokens.data(), prompt_tokens.size(), true, true) < 0) {
            fprintf(stderr, "%s: error: failed to tokenize the prompt\n", __func__);
            return Status::CANCELLED;
        }

        if (DEBUG_MODE)
            std::cout << prompt << "\n";


        // initialize the context
        llama_context_params ctx_params = llama_context_default_params();
        // n_ctx is the context size
        ctx_params.n_ctx = n_predict - 1; // n_prompt; // + n_predict - 1;
        // n_batch is the maximum number of tokens that can be processed in a single call to llama_decode
        ctx_params.n_batch = n_prompt;
        // enable performance counters
        ctx_params.no_perf = false;

        llama_context * ctx = llama_new_context_with_model(model, ctx_params);

        if (ctx == NULL) {
            if (DEBUG_MODE)
                fprintf(stderr , "%s: error: failed to create the llama_context\n" , __func__);
            return Status::CANCELLED;
        }

        // initialize the sampler

        auto sparams = llama_sampler_chain_default_params();
        sparams.no_perf = false;
        llama_sampler * smpl = llama_sampler_chain_init(sparams);

        llama_sampler_chain_add(smpl, llama_sampler_init_greedy());

        // print the prompt token-by-token
        for (auto id : prompt_tokens) {
            char buf[128];
            int n = llama_token_to_piece(model, id, buf, sizeof(buf), 0, true);
            if (n < 0) {
                fprintf(stderr, "%s: error: failed to convert token to piece\n", __func__);
                return Status::CANCELLED;
            }
            std::string s(buf, n);
            // printf("%s", s.c_str());
        }


        // prepare a batch for the prompt
        llama_batch batch = llama_batch_get_one(prompt_tokens.data(), prompt_tokens.size());

        // main loop
        int64_t t_main_start;
        int n_decode = 0;
        llama_token new_token_id;

        if (DEBUG_MODE)
            t_main_start = ggml_time_us();

        for (int n_pos = 0; n_pos + batch.n_tokens < n_prompt + n_predict; ) {
            // evaluate the current batch with the transformer model
            if (llama_decode(ctx, batch)) {
                if (DEBUG_MODE)
                    fprintf(stderr, "%s : failed to eval, return code %d\n", __func__, 1);
                // return Status::CANCELLED;
            }

            n_pos += batch.n_tokens;

            // sample the next token
            {
                new_token_id = llama_sampler_sample(smpl, ctx, -1);

                // is it an end of generation?
                if (llama_token_is_eog(model, new_token_id)) {
                    break;
                }

                char buf[128];
                int n = llama_token_to_piece(model, new_token_id, buf, sizeof(buf), 0, true);
                if (n < 0) {
                    fprintf(stderr, "%s: error: failed to convert token to piece\n", __func__);
                    return Status::CANCELLED;
                }
                std::string s(buf, n);
                if (DEBUG_MODE) {
                    printf("%s", s.c_str());
                    fflush(stdout);
                }
                generated_output += s;

                // prepare the next batch with the sampled token
                batch = llama_batch_get_one(&new_token_id, 1);

                n_decode += 1;
            }
        }

        if (DEBUG_MODE) {
            printf("\n");

            const int64_t t_main_end = ggml_time_us();

            fprintf(stderr, "%s: decoded %d tokens in %.2f s, speed: %.2f t/s\n",
                    __func__, n_decode, (t_main_end - t_main_start) / 1000000.0f, n_decode / ((t_main_end - t_main_start) / 1000000.0f));

            fprintf(stderr, "\n");
            llama_perf_sampler_print(smpl);
            llama_perf_context_print(ctx);
            fprintf(stderr, "\n");
        }

        llama_sampler_free(smpl);
        llama_free(ctx);

        /************* End llama.cpp ********************/



        // Wait for the verification result
        try {
            bool isVerified = verificationFuture.get(); // blocking call
            if (isVerified) {
                // Join the thread to clean up
                verificationThread.join();

                // Set the response
                reply->set_answer(generated_output);

                rr->recordLLMRequest(prompt, generated_output, api_key);

                return Status::OK;
            } else {
                if (DEBUG_MODE)
                    std::cerr << "User verification failed." << std::endl;
                verificationThread.join();

                return grpc::Status(grpc::StatusCode::PERMISSION_DENIED, "Unrecognized API key.");
            }
        } catch (const std::exception& ex) {
            if (DEBUG_MODE)
                std::cerr << "Error during verification: " << ex.what() << std::endl;

            if (verificationThread.joinable()) {
                verificationThread.join();
            }

            return grpc::Status(grpc::StatusCode::PERMISSION_DENIED, "Error during verification.");
        }
    }
};

static APIKeyEnforcerBase* loadConfigKeyEnforcer(std::string config_path) {
    // NOTE: toml++ can throw an exception, potentially crashing the 
    // program on an unreadable config file
    const toml::parse_result config = toml::parse_file( config_path );
    const toml::array* api_keys_array = config["server"]["api_keys"].as_array();
    const int tb_burst = config["server"]["token_bucket_burst"].value_or(-1);
    const int tb_rate = config["server"]["token_bucket_rate"].value_or(-1);

    // Extract the 'api_keys' array as a vector of strings
    std::vector<std::string> api_keys;
    if (api_keys_array) {
        for (const auto& key : *api_keys_array) {
            if (key.is_string()) {
                // std::cout << key.value_or("") << std::endl;
                api_keys.push_back(std::string{key.value_or(""s)});
            }
        }
    } else {
        std::cerr << "Missing or invalid 'api_keys' array.\n";
        return nullptr;
    }

    // Print the API keys
    std::cout << "API Keys:\n";
    for (const auto& key : api_keys) {
        std::cout << " - " << key << '\n';
    }

    // only use token bucket if values are supplied
    if (tb_burst < 0 || tb_rate < 0) {
        return new APIKeyEnforcer(api_keys);
    } else {
        return new APIKeyEnforcerTB(api_keys);
    }
}

static void writeConfigKeyEnforcer(std::string config_path, APIKeyEnforcerBase* ke) {
    try {
        std::vector<std::string> cur_keys = ke->ReturnKeys();
        toml::parse_result config = toml::parse_file( config_path );
        toml::array* api_keys_array = config["server"]["api_keys"].as_array();

        // clear existing keys from toml file object
        api_keys_array->clear();
        for (const string api_key : cur_keys) {
            if (!api_key.empty()) {
                api_keys_array->push_back(api_key);
            }
        }

        // Write the updated TOML configuration back to the file
        std::ofstream output_file(config_path);
        if (!output_file) {
            std::cerr << "Error: Unable to open the file for writing." << std::endl;
            // return without writing
            return;
        }
        output_file << config;

        std::cout << "Updated TOML file successfully written to " << config_path << std::endl;

    }
    catch (const toml::parse_error& err)
    {
        std::cerr << "toml++ parsing failed:\n" << err << std::endl;
    }
    catch (const std::exception &exc)
    {
        std::cerr << exc.what() << std::endl;
    }
}

static std::string loadConfigModelPath(std::string config_path) {
    auto config = toml::parse_file( config_path );
    return config["server"]["model_path"].value_or(""s);
    
}

static int loadConfigNPredict(std::string config_path) {
    auto config = toml::parse_file( config_path );
    return config["server"]["n_predict"].value_or(24);
}

static RecordRequestsBase* loadConfigRecordRequests(std::string config_path) {
    auto config = toml::parse_file( config_path );
    std::string post_url = config["server"]["post_request_url"].value_or(""s);

    if (post_url.empty()) {
        // NOTE: Change value if you want a different log location
        return new RecordRequests("../logs/llm-data.log");
    }

    return new RecordRequestsREST(post_url);
}

void RunServer() {
    // create logger object
    RecordRequestsBase *rr = loadConfigRecordRequests("../config/config.toml");
    APIKeyEnforcerBase *ke = loadConfigKeyEnforcer("../config/config.toml");
    std::string model_path = loadConfigModelPath("../config/config.toml");
    int n_predict = loadConfigNPredict("../config/config.toml");

    std::string server_address("0.0.0.0:50051");
    AskLLMQuestionServiceImpl service(rr, ke, model_path, n_predict);

    // Set up the server
    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    // Build and start the server
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shut down
    server->Wait();
}

int main() {
    RunServer();

    return 0;
}
