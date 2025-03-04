// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: llm_request.proto

#include "llm_request.pb.h"
#include "llm_request.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace llm_request {

static const char* AskLLMQuestion_method_names[] = {
  "/llm_request.AskLLMQuestion/PromptLLM",
};

std::unique_ptr< AskLLMQuestion::Stub> AskLLMQuestion::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< AskLLMQuestion::Stub> stub(new AskLLMQuestion::Stub(channel, options));
  return stub;
}

AskLLMQuestion::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_PromptLLM_(AskLLMQuestion_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status AskLLMQuestion::Stub::PromptLLM(::grpc::ClientContext* context, const ::llm_request::LLMInit& request, ::llm_request::LLMInference* response) {
  return ::grpc::internal::BlockingUnaryCall< ::llm_request::LLMInit, ::llm_request::LLMInference, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_PromptLLM_, context, request, response);
}

void AskLLMQuestion::Stub::async::PromptLLM(::grpc::ClientContext* context, const ::llm_request::LLMInit* request, ::llm_request::LLMInference* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::llm_request::LLMInit, ::llm_request::LLMInference, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_PromptLLM_, context, request, response, std::move(f));
}

void AskLLMQuestion::Stub::async::PromptLLM(::grpc::ClientContext* context, const ::llm_request::LLMInit* request, ::llm_request::LLMInference* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_PromptLLM_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::llm_request::LLMInference>* AskLLMQuestion::Stub::PrepareAsyncPromptLLMRaw(::grpc::ClientContext* context, const ::llm_request::LLMInit& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::llm_request::LLMInference, ::llm_request::LLMInit, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_PromptLLM_, context, request);
}

::grpc::ClientAsyncResponseReader< ::llm_request::LLMInference>* AskLLMQuestion::Stub::AsyncPromptLLMRaw(::grpc::ClientContext* context, const ::llm_request::LLMInit& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncPromptLLMRaw(context, request, cq);
  result->StartCall();
  return result;
}

AskLLMQuestion::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      AskLLMQuestion_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< AskLLMQuestion::Service, ::llm_request::LLMInit, ::llm_request::LLMInference, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](AskLLMQuestion::Service* service,
             ::grpc::ServerContext* ctx,
             const ::llm_request::LLMInit* req,
             ::llm_request::LLMInference* resp) {
               return service->PromptLLM(ctx, req, resp);
             }, this)));
}

AskLLMQuestion::Service::~Service() {
}

::grpc::Status AskLLMQuestion::Service::PromptLLM(::grpc::ServerContext* context, const ::llm_request::LLMInit* request, ::llm_request::LLMInference* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace llm_request

