#include <stdio.h>
#include <iostream>
#include <string>
#include "llama.h"
#include "protos/llm_request.pb.h"

int TestLlama() {
        // Initialize llama parameters
    llama_init_params params = llama_init_params_default();
    params.path_model = "models/llama-7b.bin";  // Path to your model

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

int main() {
    printf("Hello World!\n");

    TestLlama();
}
