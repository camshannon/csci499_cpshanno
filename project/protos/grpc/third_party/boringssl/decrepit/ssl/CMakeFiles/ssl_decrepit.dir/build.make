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
include protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/depend.make

# Include the progress variables for this target.
include protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/progress.make

# Include the compile flags for this target's objects.
include protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/flags.make

protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o: protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/flags.make
protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o: /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/decrepit/ssl/ssl_decrepit.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vagrant/Desktop/csci499_cpshanno/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/ssl && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o   -c /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/decrepit/ssl/ssl_decrepit.c

protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.i"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/ssl && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/decrepit/ssl/ssl_decrepit.c > CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.i

protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.s"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/ssl && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/decrepit/ssl/ssl_decrepit.c -o CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.s

protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o.requires:

.PHONY : protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o.requires

protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o.provides: protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o.requires
	$(MAKE) -f protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/build.make protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o.provides.build
.PHONY : protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o.provides

protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o.provides.build: protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o


ssl_decrepit: protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o
ssl_decrepit: protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/build.make

.PHONY : ssl_decrepit

# Rule to build all files generated by this target.
protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/build: ssl_decrepit

.PHONY : protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/build

protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/requires: protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/ssl_decrepit.c.o.requires

.PHONY : protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/requires

protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/clean:
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/ssl && $(CMAKE_COMMAND) -P CMakeFiles/ssl_decrepit.dir/cmake_clean.cmake
.PHONY : protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/clean

protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/depend:
	cd /home/vagrant/Desktop/csci499_cpshanno/project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/decrepit/ssl /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/ssl /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : protos/grpc/third_party/boringssl/decrepit/ssl/CMakeFiles/ssl_decrepit.dir/depend

