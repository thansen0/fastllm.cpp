# Minimum CMake version required
cmake_minimum_required(VERSION 3.18)

# Project name and version
project(fastllmcpp VERSION 0.1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Note: llama.cpp requires nvcc 11.4

# Add the executable
add_executable(fastllmcpp src/server.cpp src/RecordRequests.cpp src/APIKeyEnforcer.cpp)
add_executable(testllmcpp src/test-client.cpp)

# Find Protobuf
find_package(Protobuf REQUIRED)

# Include directories for protobuf headers
include_directories(${Protobuf_INCLUDE_DIRS} src/protos)

# Specify the generated protobuf files
set(PROTO_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/protos/llm_request.pb.cc ${CMAKE_CURRENT_SOURCE_DIR}/src/protos/llm_request.grpc.pb.cc)
set(PROTO_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/src/protos/llm_request.pb.h ${CMAKE_CURRENT_SOURCE_DIR}/src/protos/llm_request.grpc.pb.h)

# Add the generated protobuf files to the executable
target_sources(fastllmcpp PRIVATE ${PROTO_SRCS} ${PROTO_HDRS})
target_sources(testllmcpp PRIVATE ${PROTO_SRCS} ${PROTO_HDRS})

# Optionally include additional libraries or directories
# target_include_directories(fastllmcpp PRIVATE include)

include_directories(include/)
# Add the llama.cpp library and headers
add_subdirectory(libs/llama.cpp)
include_directories(libs/llama.cpp)

message(STATUS "Protobuf_LIBRARIES: ${Protobuf_LIBRARIES}")

# Link additional libraries if needed
target_link_libraries(fastllmcpp PRIVATE llama ${Protobuf_LIBRARIES} grpc++ gpr pthread absl_synchronization absl_time absl_strings absl_base)
target_link_libraries(testllmcpp PRIVATE llama ${Protobuf_LIBRARIES} grpc++ gpr pthread absl_synchronization absl_time absl_strings absl_base)
