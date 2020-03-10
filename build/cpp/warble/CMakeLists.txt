# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(warble-component)

# Find glog
find_package(glog 0.4.0 REQUIRED)

# Find GTest
find_package(GTest REQUIRED)

# Find Protobuf
find_package(Protobuf REQUIRED)

# Include header directory
include_directories(inc)

# Set headers for warble_test
set(TST_HDRS inc/warble_functions.h
	${CMAKE_BINARY_DIR}/gen/warble.pb.cc)

# Set sources for warble_test
set(TST_SRCS src/warble_test.cc 
	src/warble_functions.cc
	${CMAKE_BINARY_DIR}/gen/warble.pb.cc)

# Set executable path to bin folder
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/cpp/warble/bin)

# Create warble_test executable
add_executable(warble_test ${TST_HDRS} ${TST_SRCS})
target_link_libraries(warble_test PUBLIC GTest::GTest 
	glog::glog
	${PROTOBUF_LIBRARY})