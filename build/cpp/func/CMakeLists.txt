# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(func-component)

# Find glog
find_package(glog 0.4.0 REQUIRED)

# Find GTest
find_package(GTest REQUIRED)

# Find Protobuf
find_package(Protobuf REQUIRED)

# Include header directories
include_directories(inc 
${CMAKE_BINARY_DIR}/cpp/kvstore/inc
${CMAKE_BINARY_DIR}/cpp/warble/inc)

# Set headers for func_client
set(CLT_HDRS inc/func_client.h
	${CMAKE_BINARY_DIR}/gen/func.pb.h
	${CMAKE_BINARY_DIR}/gen/func.grpc.pb.h)

# Set sources for func_client
set(CLT_SRCS src/func_client.cc
	${CMAKE_BINARY_DIR}/gen/func.pb.cc
	${CMAKE_BINARY_DIR}/gen/func.grpc.pb.cc)

# Set headers for func_server
set(SRV_HDRS inc/func_server.h
	inc/func.h
	${CMAKE_BINARY_DIR}/cpp/kvstore/inc/kvstore_client.h
	${CMAKE_BINARY_DIR}/cpp/warble/inc/warble_functions.h
	${CMAKE_BINARY_DIR}/gen/func.pb.h
	${CMAKE_BINARY_DIR}/gen/func.grpc.pb.h
	${CMAKE_BINARY_DIR}/gen/kvstore.pb.h
	${CMAKE_BINARY_DIR}/gen/kvstore.grpc.pb.h
	${CMAKE_BINARY_DIR}/gen/warble.pb.h)

# Set sources for func_server
set(SRV_SRCS src/func_server.cc 
	src/func.cc 
	${CMAKE_BINARY_DIR}/cpp/kvstore/src/kvstore_client.cc
	${CMAKE_BINARY_DIR}/cpp/warble/src/warble_functions.cc
	${CMAKE_BINARY_DIR}/gen/func.pb.cc
	${CMAKE_BINARY_DIR}/gen/func.grpc.pb.cc
	${CMAKE_BINARY_DIR}/gen/kvstore.pb.cc
	${CMAKE_BINARY_DIR}/gen/kvstore.grpc.pb.cc
	${CMAKE_BINARY_DIR}/gen/warble.pb.cc)

# Set headers for func_test
set(TST_HDRS inc/func.h
	${CMAKE_BINARY_DIR}/cpp/warble/inc/warble_functions.h
	${CMAKE_BINARY_DIR}/cpp/kvstore/inc/kvstore_client.h
	${CMAKE_BINARY_DIR}/gen/warble.pb.h
	${CMAKE_BINARY_DIR}/gen/kvstore.pb.h
	${CMAKE_BINARY_DIR}/gen/kvstore.grpc.pb.h)

# Set sources for func_test
set(TST_SRCS src/func_test.cc
	src/func.cc
	${CMAKE_BINARY_DIR}/cpp/warble/src/warble_functions.cc
	${CMAKE_BINARY_DIR}/cpp/kvstore/src/kvstore_client.cc
	${CMAKE_BINARY_DIR}/gen/warble.pb.cc
	${CMAKE_BINARY_DIR}/gen/kvstore.pb.cc
	${CMAKE_BINARY_DIR}/gen/kvstore.grpc.pb.cc)

# Set executable path to bin folder
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/cpp/func/bin)

# Create func_client executable
add_executable(func_client ${CLT_HDRS} ${CLT_SRCS})
target_link_libraries(func_client PUBLIC gRPC::grpc++
	glog::glog
	${PROTOBUF_LIBRARY})

# Create func_server executable
add_executable(func_server ${SRV_HDRS} ${SRV_SRCS})
target_link_libraries(func_server PUBLIC gRPC::grpc++
	glog::glog
	${PROTOBUF_LIBRARY})

# Create func_test executable
add_executable(func_test ${TST_HDRS} ${TST_SRCS})
target_link_libraries(func_test PUBLIC gRPC::grpc++
	GTest::GTest 
	glog::glog
	${PROTOBUF_LIBRARY})