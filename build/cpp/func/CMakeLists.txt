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

# Include headers
include_directories(${CMAKE_BINARY_DIR}/cpp/func/inc)

# Set headers for func_client
set(CLT_HDRS inc/func_client.h
	${CMAKE_BINARY_DIR}/gen/func.grpc.h)

# Set sources for func_client
set(CLT_SRCS src/func_client.cc
	${CMAKE_BINARY_DIR}/gen/func.grpc.cc)

# Set headers for func_server
set(SRV_HDRS inc/func_server.h
	inc/func.h
	${CMAKE_BINARY_DIR}/gen/func.grpc.h)

# Set sources for func_server
set(SRV_SRCS src/func_server.cc 
	src/func.cc 
	${CMAKE_BINARY_DIR}/gen/func.grpc.cc)

# Set headers for func_test
set(TST_HDRS inc/func.h)

# Set sources for func_test
set(TST_SRCS src/func_test.cc
	src/func.cc)

# Set executable path to bin folder
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/cpp/func/bin)

# Create func_server executable
add_executable(func_server ${SRV_HDRS} ${SRV_SRCS})
target_link_libraries(func_server PUBLIC func.grpc
	glog::glog)

# Create func_client executable
add_executable(func_client ${CLT_HDRS} ${CLT_SRCS})
target_link_libraries(func_client PUBLIC func.grpc
	glog::glog)

# Create func_test executable
add_executable(func_test ${TST_HDRS} ${TST_SRCS})
target_link_libraries(func_test PUBLIC 
	GTest::GTest 
	glog::glog
	${PROTOBUF_LIBRARY})