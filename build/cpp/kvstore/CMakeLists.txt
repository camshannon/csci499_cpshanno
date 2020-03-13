# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(kvstore-component)

# Find glog
find_package(glog 0.4.0 REQUIRED)

# Find GTest
find_package(GTest REQUIRED)

# Find Protobuf
find_package(Protobuf REQUIRED)

# Find gRPC
find_package(GRPC REQUIRED)

#Include headers 
include_directories(inc)

# Set headers for kvstore_server
set(SRV_HDRS inc/kvstore_server.h
	inc/kvstore.h
	${CMAKE_BINARY_DIR}/gen/kvstore.pb.h
	${CMAKE_BINARY_DIR}/gen/kvstore.grpc.pb.h)

# Set sources for kvstore_server
set(SRV_SRCS src/kvstore_server.cc
	src/kvstore.cc
	${CMAKE_BINARY_DIR}/gen/kvstore.pb.cc
	${CMAKE_BINARY_DIR}/gen/kvstore.grpc.pb.cc)

# Set headers for kvstore_test

# Set sources for kvstore_test
set(TST_SRCS src/kvstore_test.cc
	src/kvstore.cc)

# Set executable path to bin folder
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/cpp/kvstore/bin)

# Create kvstore_server executable
add_executable(kvstore_server ${SRV_HDRS} ${SRV_SRCS})
target_link_libraries(kvstore_server PUBLIC gRPC::grpc++
	${PROTOBUF_LIBRARY}
	glog::glog)

# Create kvstore_test executable
add_executable(kvstore_test ${TST_HDRS} ${TST_SRCS})
target_link_libraries(kvstore_test PUBLIC GTest::GTest
	glog::glog)