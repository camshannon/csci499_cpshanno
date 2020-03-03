# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(func-component)

# Find glog
find_package(glog 0.4.0 REQUIRED)

# Find GTest
find_package(GTest REQUIRED)

#Include headers 
include_directories(${CMAKE_BINARY_DIR}/cpp/func/inc)

# Set sources for func_server
set(SRV_SOURCES src/func_server.cc src/func.cc)

# Set sources for func_client
set(CLT_SOURCES src/func_client.cc)

# Set sources for func_test
set(TST_SOURCES src/func_test.cc src/func.cc)

# Set executable path to bin folder
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/cpp/func/bin/func_server)

# Create func_server executable
add_executable(func_server ${SRV_SOURCES})
target_link_libraries(func_server PUBLIC func.grpc)
target_link_libraries(func_server PUBLIC glog::glog)

# Create func_client executable
add_executable(func_client ${CLT_SOURCES})
target_link_libraries(func_client PUBLIC func.grpc)
target_link_libraries(func_client PUBLIC glog::glog)

# Create func_test executable
add_executable(func_test ${TST_SOURCES})
target_link_libraries(func_test PUBLIC GTest::GTest)
add_test(func_test func_test)