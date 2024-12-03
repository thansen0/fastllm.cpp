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
    std::string PromptLLM(const std::string& api_key, const std::string& prompt_text) {
        // Prepare the request
        LLMInit request;
        request.set_apikey(api_key);
        request.set_prompt(prompt_text);

        // Prepare the response and context
        LLMInference reply;
        ClientContext context;

        // Make the gRPC call
        Status status = stub_->PromptLLM(&context, request, &reply);

        // Check if the call was successful
        if (status.ok()) {
            return reply.answer();
        } else {
            std::cerr << "gRPC call failed: " << status.error_message() << std::endl;
            return "RPC failed";
        }
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
    std::string answer = client.PromptLLM(api_key, prompt_text);

    // Print the result
    std::cout << "Answer from LLM: " << answer << std::endl;

    return 0;
}
