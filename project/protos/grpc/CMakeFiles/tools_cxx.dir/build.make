# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vagrant/Desktop/csci499_cpshanno/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vagrant/Desktop/csci499_cpshanno/project

# Utility rule file for tools_cxx.

# Include the progress variables for this target.
include protos/grpc/CMakeFiles/tools_cxx.dir/progress.make

tools_cxx: protos/grpc/CMakeFiles/tools_cxx.dir/build.make

.PHONY : tools_cxx

# Rule to build all files generated by this target.
protos/grpc/CMakeFiles/tools_cxx.dir/build: tools_cxx

.PHONY : protos/grpc/CMakeFiles/tools_cxx.dir/build

protos/grpc/CMakeFiles/tools_cxx.dir/clean:
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc && $(CMAKE_COMMAND) -P CMakeFiles/tools_cxx.dir/cmake_clean.cmake
.PHONY : protos/grpc/CMakeFiles/tools_cxx.dir/clean

protos/grpc/CMakeFiles/tools_cxx.dir/depend:
	cd /home/vagrant/Desktop/csci499_cpshanno/project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/grpc /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/CMakeFiles/tools_cxx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : protos/grpc/CMakeFiles/tools_cxx.dir/depend

