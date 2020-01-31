# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(warble-component)

add_executable(warble_server warble_server.cc)
target_link_libraries(warble_server PUBLIC warble.grpc)

add_executable(warble_client warble_client.cc)
target_link_libraries(warble_client PUBLIC warble.grpc)