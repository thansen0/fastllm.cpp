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

# Find Protobuf and CUDA
find_package(CURL REQUIRED)
find_package(Protobuf REQUIRED)
find_program(CUDA_COMPILER nvcc) # requires nvcc 11.4 or greater
option(USE_GPU "Enable GPU processing" ON)

# Disables GPU if the user doesn't have nvcc or turns it off
if (CUDA_COMPILER AND USE_GPU)
    message(STATUS "Using GPU acceleration: ${CUDA_COMPILER}")
    set(GGML_CUDA ON)
    set(ABSL_LIBS absl_synchronization absl_time absl_strings absl_base)
else()
    message(WARNING "CUDA not found or USE_GPU flag set to OFF. GGML_CUDA will be disabled.")
    set(GGML_CUDA OFF)
    set(ABSL_LIBS "")
endif()

# Include directories for protobuf headers
include_directories(${Protobuf_INCLUDE_DIRS} src/protos)

# Specify the generated protobuf files
set(PROTO_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/protos/llm_request.pb.cc ${CMAKE_CURRENT_SOURCE_DIR}/src/protos/llm_request.grpc.pb.cc)
set(PROTO_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/src/protos/llm_request.pb.h ${CMAKE_CURRENT_SOURCE_DIR}/src/protos/llm_request.grpc.pb.h)
set(JANSSON_BUILD_DOCS OFF CACHE BOOL "Disable Jansson documentation" FORCE)

# Add the generated protobuf files to the executable
target_sources(fastllmcpp PRIVATE ${PROTO_SRCS})
target_sources(testllmcpp PRIVATE ${PROTO_SRCS})

include_directories(include/)
# Add the llama.cpp library and headers
add_subdirectory(libs/llama.cpp)
include_directories(libs/llama.cpp)
add_subdirectory(libs/jansson)
include_directories(build/libs/jansson/include)
include_directories(${CURL_INCLUDE_DIR})

message(STATUS "Protobuf_LIBRARIES: ${Protobuf_LIBRARIES}")

# Link additional libraries if needed
target_link_libraries(fastllmcpp PRIVATE llama jansson ${Protobuf_LIBRARIES} grpc++ gpr pthread ${ABSL_LIBS} CURL::libcurl)
target_link_libraries(testllmcpp PRIVATE llama ${Protobuf_LIBRARIES} ${CURL_INCLUDE_DIR} grpc++ gpr pthread ${ABSL_LIBS})
