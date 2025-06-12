#include <stdio.h>
#include <iostream>
#include <string>
#include "llama.h"
#include "llm_request.pb.h"
#include <memory>
#include <grpcpp/grpcpp.h>
#include "llm_request.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using llm_request::AskLLMQuestion;
using llm_request::LLMInit;
using llm_request::LLMInference;

class LLMClient {
public:
    // Constructor, initializes the client with the server address
    LLMClient(std::shared_ptr<Channel> channel)
        : stub_(AskLLMQuestion::NewStub(channel)) {}

    // Function to prompt the LLM
    std::string StreamLLM(const std::string& api_key, const std::string& prompt_text) {
        // Prepare the request
        LLMInit request;
        request.set_apikey(api_key);
        request.set_prompt(prompt_text);

        // Prepare the response and context
        ClientContext context;

        // Make the gRPC call
        std::unique_ptr<grpc::ClientReader<LLMInference>> reader(
            stub_->StreamLLM(&context, request)
        );

        LLMInference chunk;
        std::string full_answer;
        while (reader->Read(&chunk)) {
            // chunk.answer() contains one piece of the output
            std::cout << chunk.answer() << std::flush;
            full_answer += chunk.answer();
        }

        // 4) Finish() gives the final status
        Status status = reader->Finish();
        if (!status.ok()) {
            std::cerr << "StreamLLM failed: " << status.error_message() << "\n";
            return "";
        }

        std::cout << "\n";  // newline after the last token
        return full_answer;
    }

private:
    // Stub for accessing the RPC methods
    std::unique_ptr<AskLLMQuestion::Stub> stub_;
};

int main(int argc, char* argv[]) {
    // Initialize client and connect to the server on localhost at port 50051
    LLMClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));

    // API key and prompt to send
    std::string api_key = "b150b0f9-235e-4f87-91db-d2b45da98a68";
    std::string prompt_text = "What is the capital of France?";

    if (argc == 2) {
        // reassign to command line input if exists
        prompt_text = argv[1];
    }

    std::cout << prompt_text << std::endl;
    // Call the service
    std::string answer = client.StreamLLM(api_key, prompt_text);

    return 0;
}
