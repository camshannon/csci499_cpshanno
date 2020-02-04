# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(func-component)

add_executable(func_server func_server.cc)
target_link_libraries(func_server PUBLIC func.grpc)

add_executable(func_client func_client.cc)
target_link_libraries(func_client PUBLIC func.grpc)