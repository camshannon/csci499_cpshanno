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

#Include headers 
include_directories(${CMAKE_BINARY_DIR}/cpp/warble/inc)

# Set sources for warble_client
set(CLT_SOURCES src/warble_client.cc)

# Set sources for warble_test
set(TST_SOURCES src/warble_test.cc src/warble.cc)

# Set executable path to bin folder
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/cpp/warble/bin)

# Create warble_test executable
add_executable(warble_test ${TST_SOURCES})
target_link_libraries(warble_test PUBLIC GTest::GTest)
add_test(warble_test warble_test)