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
include protos/grpc/third_party/zlib/CMakeFiles/example64.dir/depend.make

# Include the progress variables for this target.
include protos/grpc/third_party/zlib/CMakeFiles/example64.dir/progress.make

# Include the compile flags for this target's objects.
include protos/grpc/third_party/zlib/CMakeFiles/example64.dir/flags.make

protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.o: protos/grpc/third_party/zlib/CMakeFiles/example64.dir/flags.make
protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.o: /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/zlib/test/example.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vagrant/Desktop/csci499_cpshanno/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.o"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/zlib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/example64.dir/test/example.o   -c /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/zlib/test/example.c

protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/example64.dir/test/example.i"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/zlib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/zlib/test/example.c > CMakeFiles/example64.dir/test/example.i

protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/example64.dir/test/example.s"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/zlib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/zlib/test/example.c -o CMakeFiles/example64.dir/test/example.s

protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.o.requires:

.PHONY : protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.o.requires

protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.o.provides: protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.o.requires
	$(MAKE) -f protos/grpc/third_party/zlib/CMakeFiles/example64.dir/build.make protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.o.provides.build
.PHONY : protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.o.provides

protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.o.provides.build: protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.o


# Object files for target example64
example64_OBJECTS = \
"CMakeFiles/example64.dir/test/example.o"

# External object files for target example64
example64_EXTERNAL_OBJECTS =

bin/example64: protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.o
bin/example64: protos/grpc/third_party/zlib/CMakeFiles/example64.dir/build.make
bin/example64: protos/grpc/third_party/zlib/libz.so.1.2.11
bin/example64: protos/grpc/third_party/zlib/CMakeFiles/example64.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vagrant/Desktop/csci499_cpshanno/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../../../bin/example64"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/zlib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example64.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
protos/grpc/third_party/zlib/CMakeFiles/example64.dir/build: bin/example64

.PHONY : protos/grpc/third_party/zlib/CMakeFiles/example64.dir/build

protos/grpc/third_party/zlib/CMakeFiles/example64.dir/requires: protos/grpc/third_party/zlib/CMakeFiles/example64.dir/test/example.o.requires

.PHONY : protos/grpc/third_party/zlib/CMakeFiles/example64.dir/requires

protos/grpc/third_party/zlib/CMakeFiles/example64.dir/clean:
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/zlib && $(CMAKE_COMMAND) -P CMakeFiles/example64.dir/cmake_clean.cmake
.PHONY : protos/grpc/third_party/zlib/CMakeFiles/example64.dir/clean

protos/grpc/third_party/zlib/CMakeFiles/example64.dir/depend:
	cd /home/vagrant/Desktop/csci499_cpshanno/project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/zlib /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/zlib /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/zlib/CMakeFiles/example64.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : protos/grpc/third_party/zlib/CMakeFiles/example64.dir/depend
