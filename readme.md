# FastLLM-cpp



## Compile protobuf files

These can be compiled as so:

```
protoc -I=./protos --cpp_out=./protos ./protos/llm_request.proto
```
