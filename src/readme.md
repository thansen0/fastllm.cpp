# Design Patterns

This project is not just meant to be built and run, it's designed to be customized, compiled, and run. The basic structure of this app is it accepts a gRPC call from a client, processes it with the model at path `model_path` in the config file, and then returns a response. Data recording and logging is done in RecordRequests, while gRPC call verification is done using APIKeyEnforcer.

RecordRequests and APIKeyEnforcer are base classes which refer to the actual implemented function. The class used can be changed in `server.cpp`.

## RecordRequests

 - RecordRequestsBase - The base class.
 - RecordRequests - Write to a file which is in `logs/llm-data.log` by default. Uses a circular buffer to avoid memory overflows.
 - RecordRequestsNoRecord - No logging
 - RecordRequestsREST - Sends a POST request to the URL specified in the config at `post_request_url`.

All logging is done in a separate thread, so no option is slower than any other.

## APIKeyEnforcer

 - APIKeyEnforcerBase - The base class.
 - APIKeyEnforcer - Compares keys against a defined list in the config file, under the `api_keys` label.
 - APIKeyEnforcerTB - Uses the key list from APIKeyEnforcer, but adds token bucket rate limiting.

## Config File 

In `server.cpp`, if the config file does not receive arguments required for a class, it will default to a simpler class. So if you don't include `token_bucket_burst` and `token_bucket_rate`, it will not use the token bucket `APIKeyEnforcerTB` implementation and will instead use `APIKeyEnforcer`.

Similarly if you don't include `post_request_url`, the server will use `RecordRequests` by default.

If you don't want any logs saved, you must manually set that in the `server.cpp` file.

Here is a maximal `config.toml` file example. Remove things you don't want.

```
[server]
api_keys = [ 'cc3996b7-5bda-417f-9dd0-36e238d58d8e', '7f02beb5-845c-47a4-ae7a-481d0f80ee1f' ]
model_path = '../models/Llama-3.2-1B-Instruct-GGUF/Llama-3.2-1B-Instruct-Q6_K_L.gguf'
token_bucket_burst = 10
token_bucket_rate = 10
n_predict = 100
post_request_url = 'http://localhost:4000/api/prompts'
```

Here is a minimal `config.toml` file

```
[server]
api_keys = [ 'cc3996b7-5bda-417f-9dd0-36e238d58d8e', '7f02beb5-845c-47a4-ae7a-481d0f80ee1f' ]
model_path = '../models/Llama-3.2-1B-Instruct-GGUF/Llama-3.2-1B-Instruct-Q6_K_L.gguf'
```
