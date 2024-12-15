# FastLLM.cpp

FastLLM.cpp is an LLM service designed with speed and low latency in mind. Depending on your setup, by moving LLM inferencing locally, you can save 300-500ms transaction times when prompting services like Groq.

This service comes after a previous failed startup of mine. We used small models and needed as low of latency as possible. At the time everything was built in python, and I always felt like we were leaving performance on the table with python or external API's. This is, in essence, the software I wish I had when I started building.

Based on [llama.cpp](https://github.com/ggerganov/llama.cpp) and [GGML](https://github.com/ggerganov/ggml). It is recommended that users of the project fork it, and make changes to the APIKeyEnforcer and RecordRequests to better fit their use case.

Please feel free to contact me at **contact@thomashansen.xyz** if you have any questions about use. I'd be happy to help anyone getting started or thinking about using FastLLM.cpp, especially as this is a new project.

## NOTICE

While this project can be used in production, it's in an early stage and may see major changes in the future.

## Requirements

 - nvcc version 11.4 or greater
 - GPU for fast inference (CPU works for testing but is slow)
 - linux

# Setup
## Build FastLLM.cpp

You will have to build the protobuf files, and then build the actual project. There are no binaries to pull down.

```
apt install build-essential cmake ninja-build git pkg-config libssl-dev protobuf-compiler libgrpc++-dev libprotobuf-dev libgrpc-dev protobuf-compiler-grpc
apt install libabsl-dev # for GPU

git submodule update --init     # clones llama.cpp

protoc -I=./protos --cpp_out=./protos --grpc_out=./protos --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ./protos/llm_request.proto

mkdir build
cd build            # Non-ninja commands
cmake -G Ninja ..   # cmake ..
ninja               # cmake --build .
```

For building without GPU support, you may set the flag `USE\_GPU=OFF`. GPU support will also be turned off if cmake doesn't detect nvcc (the CUDA compiler).

```
cmake -G Ninja ../ -DUSE_GPU=OFF
```

## Config file Setup

You will need to set up the config file in `./config/config.toml`. The config file will look something like this, I added `uuid`'s as API keys. If you don't want to use rate limiting on your service, simply don't add the `token_bucket_burst` and/or `token_bucket_rate` value and it will default to ignore them.

```
[server]
token_bucket_rate=10
token_bucket_burst=10
model_path="/home/username/Volumes/models/Llama-3.2-1B-Instruct-GGUF/Llama-3.2-1B-Instruct-Q6_K_L.gguf"
api_keys=["fc513bbb-6306-42d7-b385-48c3c2240d11", "866e974d-8308-4620-9706-26684a640df0"]
```

You must separately clone and link to a GUFF model. [This one](https://huggingface.co/bartowski/Llama-3.2-1B-Instruct-GGUF) works and is easily accessible.

```
git clone https://huggingface.co/bartowski/Llama-3.2-1B-Instruct-GGUF
```

## Running on Server

If you don't already have opinions on this I recommend running it as a systemd service. There are a [number of examples](https://www.shellhacks.com/systemd-service-file-example/) on how to do it.

## Contributions

Feel free to create issues as you see them or submit PR's. Also feel free to email me at contact@thomashansen.xyz if you have questions or message me on [X](https://x.com/mongocompass).

## Donate

I also appreciate donations!

BTC Address: `3QDGJyRWiVEUyCytQBWJ5h3kVQAca8pZ1L`
XMR Address: `85pJmtRzE6zWhSpggKyiXHDG56FM6ydStYBRfuU4FV5Y1uCvnBwAuacRNRNkAJmAR76fzBF5QQeBiEnuaQJeiHaDF7D6xFb`

# License

This project is licensed with the unlicense. The idea is you may use this project however you wish, without having to attribute it to the original source. You may clone the repo into your company's private code and then place it under your company's private license. We do appreciate contributions though!
