# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(cmd-component)

# Find glog
find_package(glog REQUIRED)

# Find GTest
find_package(GTest REQUIRED)

# Find GFlags
find_package(gflags REQUIRED)

# Find Protobuf
find_package(Protobuf REQUIRED)

# Find gRPC
find_package(GRPC REQUIRED)

# Include header directories
include_directories(
${CMAKE_BINARY_DIR}/cpp/cmd/inc
${CMAKE_BINARY_DIR}/cpp/func/inc
${CMAKE_BINARY_DIR}/cpp/kvstore/inc
${CMAKE_BINARY_DIR}/cpp/warble/inc)

# Set headers for cmd
set(WRBL_HDRS inc/cmd.h
	${CMAKE_BINARY_DIR}/cpp/func/inc/func_client.h
	${CMAKE_BINARY_DIR}/cpp/kvstore/inc/kvstore.h
	${CMAKE_BINARY_DIR}/cpp/kvstore/inc/kvstore_client.h
	${CMAKE_BINARY_DIR}/gen/func.pb.h
	${CMAKE_BINARY_DIR}/gen/func.grpc.pb.h
	${CMAKE_BINARY_DIR}/gen/kvstore.pb.h
	${CMAKE_BINARY_DIR}/gen/kvstore.grpc.pb.h
	${CMAKE_BINARY_DIR}/gen/warble.pb.h)

# Set sources for main
set(WRBL_SRCS src/main.cc
	src/cmd.cc
	${CMAKE_BINARY_DIR}/cpp/func/src/func_client.cc
	${CMAKE_BINARY_DIR}/cpp/kvstore/src/kvstore.cc
	${CMAKE_BINARY_DIR}/cpp/kvstore/src/kvstore_client.cc
	${CMAKE_BINARY_DIR}/gen/func.pb.cc
	${CMAKE_BINARY_DIR}/gen/func.grpc.pb.cc
	${CMAKE_BINARY_DIR}/gen/kvstore.pb.cc
	${CMAKE_BINARY_DIR}/gen/kvstore.grpc.pb.cc
	${CMAKE_BINARY_DIR}/gen/warble.pb.cc)

# Set executable path to bin folder
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Create warble executable
add_executable(warble ${WRBL_HDRS} ${WRBL_SRCS})
target_link_libraries(warble PUBLIC gRPC::grpc++
	gflags
	glog::glog
	${PROTOBUF_LIBRARY})