cmake_minimum_required(VERSION 3.13.0)

project(build)

# C++ Standard
add_compile_options(-std=c++17)

# add glog installation directory
list(APPEND CMAKE_PREFIX_PATH /usr/include/glog)

# Add cpp subdirectory for building
add_subdirectory(cpp)