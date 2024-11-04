# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(fastllmcpp VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(fastllmcpp src/main.cpp)
add_executable(testllmcpp src/test-client.cpp)

# Find Protobuf
#find_package(gRPC REQUIRED)
find_package(Protobuf REQUIRED)

# Include directories for protobuf headers
include_directories(${Protobuf_INCLUDE_DIRS} src/protos)

# Link Protobuf libraries
target_link_libraries(fastllmcpp PRIVATE llama ${Protobuf_LIBRARIES})

# Specify the generated protobuf files
set(PROTO_SRCS src/protos/llm_request.pb.cc src/protos/llm_request.grpc.pb.cc)
set(PROTO_HDRS src/protos/llm_request.pb.h src/protos/llm_request.grpc.pb.h)

# Add the generated protobuf files to the executable
target_sources(fastllmcpp PRIVATE ${PROTO_SRCS} ${PROTO_HDRS})
target_sources(testllmcpp PRIVATE ${PROTO_SRCS} ${PROTO_HDRS})

# Optionally include additional libraries or directories
# target_include_directories(fastllmcpp PRIVATE include)

# Add the llama.cpp library and headers
add_subdirectory(libs/llama.cpp)
include_directories(libs/llama.cpp)

# Link additional libraries if needed
# target_link_libraries(fastllmcpp PRIVATE llama)
# target_link_libraries(fastllmcpp PRIVATE llama ${Protobuf_LIBRARIES} ${gRPC_LIBRARIES} grpc++ pthread)
target_link_libraries(fastllmcpp PRIVATE llama ${Protobuf_LIBRARIES} grpc++ pthread)
target_link_libraries(testllmcpp PRIVATE llama ${Protobuf_LIBRARIES} grpc++ pthread)
