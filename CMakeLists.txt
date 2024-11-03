# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(fastllmcpp VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(fastllmcpp src/main.cpp)

# Optionally include additional libraries or directories
# target_include_directories(MyProject PRIVATE include)

# Link additional libraries if needed
# target_link_libraries(MyProject PRIVATE some_library)

