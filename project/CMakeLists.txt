# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(project)

# C++ Standard
add_compile_options(-std=c++17)

# Set gRPC CMake module
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

add_subdirectory(protos)
add_subdirectory(src)