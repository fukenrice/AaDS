cmake_minimum_required(VERSION 3.16)
project(Contest_16+)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

add_executable(Contest_16+ Contest_21/Task_5.cpp)
