# FastLLM.cpp

## Build FastLLM.cpp

I *highly* recommend building this using ninja. To do this run 

```
mkdir build
cd build            # Non-ninja commands
cmake -G Ninja ..   # cmake ..
ninja               # cmake --build .
```



## Compile protobuf files

These can be compiled as so:

```
protoc -I=./protos --cpp_out=./protos ./protos/llm_request.proto
```
