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

# Include any dependencies generated for this target.
include protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/depend.make

# Include the progress variables for this target.
include protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/progress.make

# Include the compile flags for this target's objects.
include protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/flags.make

protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o: protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/flags.make
protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o: /home/vagrant/Desktop/csci499_cpshanno/grpc/src/compiler/cpp_plugin.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vagrant/Desktop/csci499_cpshanno/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o -c /home/vagrant/Desktop/csci499_cpshanno/grpc/src/compiler/cpp_plugin.cc

protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.i"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vagrant/Desktop/csci499_cpshanno/grpc/src/compiler/cpp_plugin.cc > CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.i

protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.s"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vagrant/Desktop/csci499_cpshanno/grpc/src/compiler/cpp_plugin.cc -o CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.s

protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o.requires:

.PHONY : protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o.requires

protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o.provides: protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o.requires
	$(MAKE) -f protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/build.make protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o.provides.build
.PHONY : protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o.provides

protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o.provides.build: protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o


# Object files for target grpc_cpp_plugin
grpc_cpp_plugin_OBJECTS = \
"CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o"

# External object files for target grpc_cpp_plugin
grpc_cpp_plugin_EXTERNAL_OBJECTS =

bin/grpc_cpp_plugin: protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o
bin/grpc_cpp_plugin: protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/build.make
bin/grpc_cpp_plugin: protos/grpc/third_party/protobuf/libprotoc.a
bin/grpc_cpp_plugin: protos/grpc/third_party/protobuf/libprotobuf.a
bin/grpc_cpp_plugin: protos/grpc/libgrpc_plugin_support.a
bin/grpc_cpp_plugin: protos/grpc/third_party/protobuf/libprotoc.a
bin/grpc_cpp_plugin: protos/grpc/third_party/protobuf/libprotobuf.a
bin/grpc_cpp_plugin: protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vagrant/Desktop/csci499_cpshanno/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/grpc_cpp_plugin"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/grpc_cpp_plugin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/build: bin/grpc_cpp_plugin

.PHONY : protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/build

protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/requires: protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/src/compiler/cpp_plugin.cc.o.requires

.PHONY : protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/requires

protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/clean:
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc && $(CMAKE_COMMAND) -P CMakeFiles/grpc_cpp_plugin.dir/cmake_clean.cmake
.PHONY : protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/clean

protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/depend:
	cd /home/vagrant/Desktop/csci499_cpshanno/project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/grpc /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : protos/grpc/CMakeFiles/grpc_cpp_plugin.dir/depend

