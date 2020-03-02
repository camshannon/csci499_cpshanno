# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(kvstore-component)

# Find glog
find_package(glog 0.4.0 REQUIRED)

# Find GTest
find_package(GTest REQUIRED)

#Include headers 
include_directories(${CMAKE_BINARY_DIR}/cpp/kvstore/inc)

# Set sources for kvstore_server
set(SRV_SOURCES src/kvstore_server.cc src/kvstore.cc)

# Set sources for kvstore_client
set(CLT_SOURCES src/kvstore_client.cc)

# Set sources for kvstore_test
set(TST_SOURCES src/kvstore_test.cc src/kvstore.cc)
 
# Create kvstore_server executable
add_executable(kvstore_server ${SRV_SOURCES})
target_link_libraries(kvstore_server PUBLIC kvstore.grpc)
target_link_libraries(kvstore_server PUBLIC glog::glog)

# Create kvstore_client executable
add_executable(kvstore_client ${CLT_SOURCES})
target_link_libraries(kvstore_client PUBLIC kvstore.grpc)
target_link_libraries(kvstore_client PUBLIC glog::glog)

# Create kvstore_test executable
add_executable(kvstore_test ${TST_SOURCES})
target_link_libraries(kvstore_test PUBLIC GTest::GTest)
add_test(kvstore_test kvstore_test)