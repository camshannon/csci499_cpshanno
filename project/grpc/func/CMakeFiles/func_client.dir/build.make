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
include grpc/func/CMakeFiles/func_client.dir/depend.make

# Include the progress variables for this target.
include grpc/func/CMakeFiles/func_client.dir/progress.make

# Include the compile flags for this target's objects.
include grpc/func/CMakeFiles/func_client.dir/flags.make

grpc/func/CMakeFiles/func_client.dir/func_client.cc.o: grpc/func/CMakeFiles/func_client.dir/flags.make
grpc/func/CMakeFiles/func_client.dir/func_client.cc.o: grpc/func/func_client.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vagrant/Desktop/csci499_cpshanno/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object grpc/func/CMakeFiles/func_client.dir/func_client.cc.o"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/grpc/func && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/func_client.dir/func_client.cc.o -c /home/vagrant/Desktop/csci499_cpshanno/project/grpc/func/func_client.cc

grpc/func/CMakeFiles/func_client.dir/func_client.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/func_client.dir/func_client.cc.i"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/grpc/func && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vagrant/Desktop/csci499_cpshanno/project/grpc/func/func_client.cc > CMakeFiles/func_client.dir/func_client.cc.i

grpc/func/CMakeFiles/func_client.dir/func_client.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/func_client.dir/func_client.cc.s"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/grpc/func && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vagrant/Desktop/csci499_cpshanno/project/grpc/func/func_client.cc -o CMakeFiles/func_client.dir/func_client.cc.s

grpc/func/CMakeFiles/func_client.dir/func_client.cc.o.requires:

.PHONY : grpc/func/CMakeFiles/func_client.dir/func_client.cc.o.requires

grpc/func/CMakeFiles/func_client.dir/func_client.cc.o.provides: grpc/func/CMakeFiles/func_client.dir/func_client.cc.o.requires
	$(MAKE) -f grpc/func/CMakeFiles/func_client.dir/build.make grpc/func/CMakeFiles/func_client.dir/func_client.cc.o.provides.build
.PHONY : grpc/func/CMakeFiles/func_client.dir/func_client.cc.o.provides

grpc/func/CMakeFiles/func_client.dir/func_client.cc.o.provides.build: grpc/func/CMakeFiles/func_client.dir/func_client.cc.o


# Object files for target func_client
func_client_OBJECTS = \
"CMakeFiles/func_client.dir/func_client.cc.o"

# External object files for target func_client
func_client_EXTERNAL_OBJECTS =

bin/func_client: grpc/func/CMakeFiles/func_client.dir/func_client.cc.o
bin/func_client: grpc/func/CMakeFiles/func_client.dir/build.make
bin/func_client: grpc/func/CMakeFiles/func_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vagrant/Desktop/csci499_cpshanno/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/func_client"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/grpc/func && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/func_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
grpc/func/CMakeFiles/func_client.dir/build: bin/func_client

.PHONY : grpc/func/CMakeFiles/func_client.dir/build

grpc/func/CMakeFiles/func_client.dir/requires: grpc/func/CMakeFiles/func_client.dir/func_client.cc.o.requires

.PHONY : grpc/func/CMakeFiles/func_client.dir/requires

grpc/func/CMakeFiles/func_client.dir/clean:
	cd /home/vagrant/Desktop/csci499_cpshanno/project/grpc/func && $(CMAKE_COMMAND) -P CMakeFiles/func_client.dir/cmake_clean.cmake
.PHONY : grpc/func/CMakeFiles/func_client.dir/clean

grpc/func/CMakeFiles/func_client.dir/depend:
	cd /home/vagrant/Desktop/csci499_cpshanno/project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/project/grpc/func /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/project/grpc/func /home/vagrant/Desktop/csci499_cpshanno/project/grpc/func/CMakeFiles/func_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : grpc/func/CMakeFiles/func_client.dir/depend

