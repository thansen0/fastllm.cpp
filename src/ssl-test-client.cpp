#include <iostream>
#include <string>
#include "llama.h"
#include "llm_request.pb.h"
#include <grpcpp/grpcpp.h>
#include "llm_request.grpc.pb.h"
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using llm_request::AskLLMQuestion;
using llm_request::LLMInit;
using llm_request::LLMInference;

using namespace std;

/* 
 * Generates SSL certificate
 * 
 * Can all be replaced by reading in a certificate/pem file instead
 */
bool GenerateSelfSignedCert(std::string &pem_cert, std::string &pem_key) {
    // 1) Generate a 2048-bit RSA key
#if OPENSSL_VERSION_NUMBER >= 0x30000000L
    EVP_PKEY *pkey = EVP_RSA_gen(2048);
#else
    RSA *rsa = RSA_generate_key(2048, RSA_F4, nullptr, nullptr);
    EVP_PKEY *pkey = EVP_PKEY_new();
    EVP_PKEY_assign_RSA(pkey, rsa);
#endif

    if (!pkey) return false;

    // 2) Create X509 certificate, set validity, public key, subject/issuer name = “localhost”
    X509 *x509 = X509_new();
    ASN1_INTEGER_set(X509_get_serialNumber(x509), 1);
    X509_gmtime_adj(X509_get_notBefore(x509), 0);
    X509_gmtime_adj(X509_get_notAfter(x509), 31536000L);
    X509_set_pubkey(x509, pkey);

    X509_NAME *name = X509_get_subject_name(x509);
    X509_NAME_add_entry_by_txt(
        name, "CN",  MBSTRING_ASC,
        reinterpret_cast<const unsigned char*>("localhost"),
        -1, -1, 0
    );
    // self-signed → issuer = subject
    X509_set_issuer_name(x509, name);

    // 3) Sign certificate with our key
    X509_sign(x509, pkey, EVP_sha256());

    // 4) Dump to PEM strings
    BIO *cert_bio = BIO_new(BIO_s_mem());
    PEM_write_bio_X509(cert_bio, x509);
    {
        char *data_ptr = nullptr;
        long len = BIO_get_mem_data(cert_bio, &data_ptr);
        pem_cert.assign(data_ptr, len);
    }
    BIO_free(cert_bio);

    BIO *key_bio = BIO_new(BIO_s_mem());
    PEM_write_bio_PrivateKey(key_bio, pkey, nullptr, nullptr, 0, nullptr, nullptr);
    {
        char *data_ptr = nullptr;
        long len = BIO_get_mem_data(key_bio, &data_ptr);
        pem_key.assign(data_ptr, len);
    }
    BIO_free(key_bio);

    X509_free(x509);
    EVP_PKEY_free(pkey);
    return true;
}

int main(int argc, char* argv[]) {
    // API key and prompt to send
    std::string api_key = "b150b0f9-235e-4f87-91db-d2b45da98a68";
    std::string prompt_text = "What is the capital of France?";

    // 1) Generate cert+key
    std::string cert_chain, private_key;
    if (!GenerateSelfSignedCert(cert_chain, private_key)) {
        std::cerr << "Failed to generate cert/key\n";
        return 1;
    }

    // 2) Prepare gRPC SSL credentials
    grpc::SslCredentialsOptions ssl_opts;
    ssl_opts.pem_root_certs   = cert_chain;    // trust our own cert
    ssl_opts.pem_cert_chain   = cert_chain;    // present same cert to server
    ssl_opts.pem_private_key  = private_key;   // present our key

    auto channel_creds = grpc::SslCredentials(ssl_opts);

    // 3) Override the target name for TLS hostname check
    grpc::ChannelArguments channel_args;
    channel_args.SetSslTargetNameOverride("localhost");

    // 4) Create a secure channel to your local server
    auto channel = grpc::CreateCustomChannel(
        "127.0.0.1:50051",
        channel_creds,
        channel_args
    );

    // 5) Build your stub and do the RPC
    auto client = llm_request::AskLLMQuestion::NewStub(channel);
    
    llm_request::LLMInit request;
    request.set_apikey(api_key);
    request.set_prompt(prompt_text);

    llm_request::LLMInference reply;
    grpc::ClientContext context;

    if (argc == 2) {
        // reassign to command line input if exists
        prompt_text = argv[1];
    }

    std::cout << prompt_text << std::endl;

    // 6) Prompt LLM and call service
    grpc::Status status = client->PromptLLM(&context, request, &reply);
    if (!status.ok()) {
        std::cerr << "RPC failed: "
                    << status.error_code() << " - "
                    << status.error_message() << "\n";
        return 1;
    }

    // Print the result
    std::cout << "Answer from LLM: " << reply.answer() << std::endl;

    return 0;
}
