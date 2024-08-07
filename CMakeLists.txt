cmake_minimum_required(VERSION 3.16)
project(IniParser LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(IniParser src/main.cpp)
add_subdirectory(src)

target_include_directories(IniParser PRIVATE include)