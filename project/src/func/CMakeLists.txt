# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(func-component)

set(hw_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.pb.cc")
set(hw_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.pb.h")
set(hw_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.grpc.pb.cc")
set(hw_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.grpc.pb.h")

add_executable(func_server
	${CMAKE_CURRENT_SOURCE_DIR}/func_server.cc
	${PROTO_SRCS}
	${GRPC_SRCS})
target_link_libraries(func_server)