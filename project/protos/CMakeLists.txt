# Minimum CMake required
cmake_minimum_required(VERSION 3.10.0)

# Project
project(proto-generations)

# Find required protobuf package
find_package(Protobuf REQUIRED)

# Add GRPC subdirectory
add_subdirectory(../../grpc ${CMAKE_CURRENT_BINARY_DIR}/grpc EXCLUDE_FROM_ALL)

# Use GRPC targets directly from build
set(_PROTOBUF_LIBPROTOBUF libprotobuf)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protoc>)
set(_GRPC_GRPCPP_UNSECURE grpc++_unsecure)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)

# Set protos list
set(protos func kvstore warble)

foreach(proto ${protos})
  get_filename_component({proto}_proto "${proto}.proto" ABSOLUTE)
	get_filename_component({proto}_proto_path "${${proto}_proto}" PATH)

  # Generated proto sources
	set(${proto}_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/${proto}.pb.cc")
  set(${proto}_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/${proto}.pb.h")
	set(${proto}_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/${proto}.grpc.pb.cc")
	set(${proto}_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/${proto}.grpc.pb.h")
	add_custom_command(
    		OUTPUT "${${proto}_proto_srcs}" "${${proto}_proto_hdrs}" "${${proto}_grpc_srcs}" "${${proto}_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${${proto}_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${${proto}_proto}"
      DEPENDS "${${proto}_proto}")
endforeach()

# Include generated *.pb.h files
include_directories(${CMAKE_BINARY_DIR})

#Targets
foreach(_target
  func_client func_server
  kvstore_client kvstore_server
  warble_client warble_server)
  add_executable(${_target} "${_target}.cc"
    ${hw_proto_srcs}
    ${hw_grpc_srcs})
  target_link_libraries(${_target}
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF})
endforeach()