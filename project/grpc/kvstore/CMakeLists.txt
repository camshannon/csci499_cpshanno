# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(kvstore-component)

add_executable(kvstore_server kvstore_server.cc)
target_link_libraries(kvstore_server PUBLIC kvstore.grpc)

add_executable(kvstore_client kvstore_client.cc)
target_link_libraries(kvstore_client PUBLIC kvstore.grpc)