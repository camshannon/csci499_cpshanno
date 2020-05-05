cmake_minimum_required(VERSION 3.13.0)

project(project-components)

# Set components list
set(components cmd func kvstore warble)

# Make sure the generated proto header and source files are visible to the other projects
include_directories(${CMAKE_BINARY_DIR}/gen
	${CMAKE_BINARY_DIR/protos})

foreach(component ${components})
    add_subdirectory(${component})
endforeach()
