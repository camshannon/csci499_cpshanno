# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(proto-generations)

# Find required protobuf package
find_package(Protobuf REQUIRED)

# Find required GRPC package
find_package(GRPC REQUIRED)

# Get the filenames of all the proto files.
file(GLOB PROTO_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.proto)

# Generate header and source files for all the proto files
foreach(proto ${PROTO_FILES})
    # Get filename without extension
    get_filename_component(PROTO_NAME_WE ${proto} NAME_WE)
    get_filename_component(PROTO_NAME ${proto} NAME)
    # message(STATUS "Generating Protobuf Code for ${PROTO_NAME}")
    protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${CMAKE_CURRENT_BINARY_DIR} ${proto})
    add_library(${PROTO_NAME_WE}.proto STATIC ${PROTO_SRCS} ${PROTO_HDRS})
    target_include_directories(${PROTO_NAME_WE}.proto PUBLIC ${Protobuf_INCLUDE_DIRS})
    # message(STATUS "Generating gRPC Code for ${PROTO_NAME}")
    grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${CMAKE_CURRENT_BINARY_DIR} ${proto})
    add_library(${PROTO_NAME_WE}.grpc STATIC ${GRPC_SRCS} ${GRPC_HDRS} ${PROTO_SRCS} ${PROTO_HDRS})
    target_include_directories(${PROTO_NAME_WE}.grpc PUBLIC ${GRPC_INCLUDE_DIR})
    # target_link_libraries(${PROTO_NAME_WE}.grpc gRPC::grpc++)
    target_link_libraries(${PROTO_NAME_WE}.grpc gRPC::grpc++_reflection)
endforeach()



