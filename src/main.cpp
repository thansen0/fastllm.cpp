#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "llama.h"
#include "protos/llm_request.pb.h"
#include <memory>
#include <grpcpp/grpcpp.h>
#include "llm_request.grpc.pb.h"

using namespace std;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using llm_request::AskLLMQuestion;
using llm_request::LLMInit;
using llm_request::LLMInference;


class WriteRequests {
private:
    std::ofstream logFile;

public:
    // Constructor: Initializes and opens the file
    WriteRequests(const std::string& filePath) {
        logFile.open(filePath);
        if (!logFile.is_open()) {
            throw std::ios_base::failure("Failed to open log file.");
        }
    }

    // Destructor: Closes the file automatically on object destruction
    ~WriteRequests() {
        if (logFile.is_open()) {
            printf("CLOSING logfile");
            logFile.close();
        }
    }

    // Method to write a log entry in CSV format
    void writeLLMRequest(const std::string& prompt, const std::string& result, const std::string& user_uuid) {
        if (logFile.is_open()) {
            logFile << "\"" << prompt << "\",\"" << result << "," << user_uuid << "\"\n";
            logFile.flush();
        } else {
            std::cerr << "Log file is not open for writing.\n";
        }
    }
};

// Service implementation
class AskLLMQuestionServiceImpl final : public AskLLMQuestion::Service {
private:
    WriteRequests *wr;

public:
    AskLLMQuestionServiceImpl(WriteRequests *wr_ptr) {
        wr = wr_ptr;
    }

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
        std::string answer = "This is a placeholder answer";

        // Set the response
        reply->set_answer(answer);

        try{
            wr->writeLLMRequest(prompt, answer, api_key);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }



        return Status::OK;
    }
};

void RunServer() {
    // TODO read in config information

    // create logger object
    WriteRequests *wr = new WriteRequests("/home/thomas/Code/fastllmcpp/fastllmcpp/logs/llm-data.log");

    std::string server_address("0.0.0.0:50051");
    AskLLMQuestionServiceImpl service(wr);

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
