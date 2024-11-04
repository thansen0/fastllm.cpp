#include <stdio.h>
#include <iostream>
#include <string>
#include "llama.h"
#include "protos/llm_request.pb.h"
#include <memory>
#include <grpcpp/grpcpp.h>
#include "llm_request.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using llm_request::AskLLMQuestion;
using llm_request::LLMInit;
using llm_request::LLMInference;


/*
int TestLlama() {
        // Initialize llama parameters
    llama_init_params params = llama_init_params_default();
    params.path_model = "Llama-3.2-3B-Instruct-uncensored-GGUF/Llama-3.2-3B-Instruct-uncensored.Q2_K.gguf";  // Path to your model

    // Initialize the model context
    llama_context *ctx = llama_init_from_file(params.path_model.c_str(), params);
    if (!ctx) {
        std::cerr << "Failed to load the model." << std::endl;
        return 1;
    }

    // Define the prompt
    const std::string prompt = "The future of AI is";
    llama_token tokens[128];
    int n_tokens = llama_tokenize(ctx, prompt.c_str(), tokens, 128, true);

    // Evaluate the model with the prompt
    if (llama_eval(ctx, tokens, n_tokens, 0, 4)) {
        std::cerr << "Failed to evaluate model." << std::endl;
        llama_free(ctx);
        return 1;
    }

    // Generate text based on the prompt
    std::cout << prompt;
    for (int i = 0; i < 50; i++) {  // Generate 50 tokens
        llama_token new_token = llama_sample_top_p_top_k(ctx, NULL, 0.9, 40);
        std::cout << llama_token_to_str(ctx, new_token);
        
        // Feed the new token back into the model
        if (llama_eval(ctx, &new_token, 1, i + n_tokens, 4)) {
            std::cerr << "Failed to evaluate model." << std::endl;
            break;
        }
    }

    // Free resources
    llama_free(ctx);
    return 0;
}
*/

// Service implementation
class AskLLMQuestionServiceImpl final : public AskLLMQuestion::Service {
public:
    // Implementation of the PromptLLM RPC
    Status PromptLLM(ServerContext* context, const LLMInit* request, LLMInference* reply) override {
        // Access the fields in the request
        std::string api_key = request->apikey();
        std::string prompt = request->prompt();

        // Log or process the request data as needed
        std::cout << "Received API key: " << api_key << std::endl;
        std::cout << "Received Prompt: " << prompt << std::endl;

        // Process and create a response
        // In a real scenario, replace this with the logic to generate an answer.
        std::string answer = "This is a placeholder answer.";

        // Set the response
        reply->set_answer(answer);

        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    AskLLMQuestionServiceImpl service;

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
    printf("Hello World!\n");
    RunServer();

    return 0;
}
