# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(build)

# C++ Standard
add_compile_options(-std=c++17 -Wall -g)

# Set gRPC CMake module
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Find required protobuf package
find_package(Protobuf REQUIRED)

# Find required GRPC package
find_package(GRPC REQUIRED)

# Add cpp subdirectory for building
add_subdirectory(cpp)