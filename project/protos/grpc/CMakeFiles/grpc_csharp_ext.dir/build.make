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
include protos/grpc/CMakeFiles/grpc_csharp_ext.dir/depend.make

# Include the progress variables for this target.
include protos/grpc/CMakeFiles/grpc_csharp_ext.dir/progress.make

# Include the compile flags for this target's objects.
include protos/grpc/CMakeFiles/grpc_csharp_ext.dir/flags.make

protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o: protos/grpc/CMakeFiles/grpc_csharp_ext.dir/flags.make
protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o: /home/vagrant/Desktop/csci499_cpshanno/grpc/src/csharp/ext/grpc_csharp_ext.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vagrant/Desktop/csci499_cpshanno/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o   -c /home/vagrant/Desktop/csci499_cpshanno/grpc/src/csharp/ext/grpc_csharp_ext.c

protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.i"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vagrant/Desktop/csci499_cpshanno/grpc/src/csharp/ext/grpc_csharp_ext.c > CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.i

protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.s"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vagrant/Desktop/csci499_cpshanno/grpc/src/csharp/ext/grpc_csharp_ext.c -o CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.s

protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o.requires:

.PHONY : protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o.requires

protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o.provides: protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o.requires
	$(MAKE) -f protos/grpc/CMakeFiles/grpc_csharp_ext.dir/build.make protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o.provides.build
.PHONY : protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o.provides

protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o.provides.build: protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o


# Object files for target grpc_csharp_ext
grpc_csharp_ext_OBJECTS = \
"CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o"

# External object files for target grpc_csharp_ext
grpc_csharp_ext_EXTERNAL_OBJECTS =

protos/grpc/libgrpc_csharp_ext.so: protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o
protos/grpc/libgrpc_csharp_ext.so: protos/grpc/CMakeFiles/grpc_csharp_ext.dir/build.make
protos/grpc/libgrpc_csharp_ext.so: protos/grpc/libgrpc.a
protos/grpc/libgrpc_csharp_ext.so: protos/grpc/libgpr.a
protos/grpc/libgrpc_csharp_ext.so: protos/grpc/third_party/boringssl/ssl/libssl.a
protos/grpc/libgrpc_csharp_ext.so: protos/grpc/third_party/boringssl/crypto/libcrypto.a
protos/grpc/libgrpc_csharp_ext.so: protos/grpc/third_party/zlib/libz.a
protos/grpc/libgrpc_csharp_ext.so: protos/grpc/third_party/cares/cares/lib/libcares.a
protos/grpc/libgrpc_csharp_ext.so: protos/grpc/libaddress_sorting.a
protos/grpc/libgrpc_csharp_ext.so: protos/grpc/CMakeFiles/grpc_csharp_ext.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vagrant/Desktop/csci499_cpshanno/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libgrpc_csharp_ext.so"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/grpc_csharp_ext.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
protos/grpc/CMakeFiles/grpc_csharp_ext.dir/build: protos/grpc/libgrpc_csharp_ext.so

.PHONY : protos/grpc/CMakeFiles/grpc_csharp_ext.dir/build

protos/grpc/CMakeFiles/grpc_csharp_ext.dir/requires: protos/grpc/CMakeFiles/grpc_csharp_ext.dir/src/csharp/ext/grpc_csharp_ext.c.o.requires

.PHONY : protos/grpc/CMakeFiles/grpc_csharp_ext.dir/requires

protos/grpc/CMakeFiles/grpc_csharp_ext.dir/clean:
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc && $(CMAKE_COMMAND) -P CMakeFiles/grpc_csharp_ext.dir/cmake_clean.cmake
.PHONY : protos/grpc/CMakeFiles/grpc_csharp_ext.dir/clean

protos/grpc/CMakeFiles/grpc_csharp_ext.dir/depend:
	cd /home/vagrant/Desktop/csci499_cpshanno/project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/grpc /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/CMakeFiles/grpc_csharp_ext.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : protos/grpc/CMakeFiles/grpc_csharp_ext.dir/depend

