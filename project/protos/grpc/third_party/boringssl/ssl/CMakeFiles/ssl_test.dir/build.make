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
include protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/depend.make

# Include the progress variables for this target.
include protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/progress.make

# Include the compile flags for this target's objects.
include protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/flags.make

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.o: protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/flags.make
protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.o: /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/ssl/span_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vagrant/Desktop/csci499_cpshanno/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.o"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/ssl && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ssl_test.dir/span_test.cc.o -c /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/ssl/span_test.cc

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ssl_test.dir/span_test.cc.i"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/ssl && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/ssl/span_test.cc > CMakeFiles/ssl_test.dir/span_test.cc.i

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ssl_test.dir/span_test.cc.s"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/ssl && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/ssl/span_test.cc -o CMakeFiles/ssl_test.dir/span_test.cc.s

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.o.requires:

.PHONY : protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.o.requires

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.o.provides: protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.o.requires
	$(MAKE) -f protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/build.make protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.o.provides.build
.PHONY : protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.o.provides

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.o.provides.build: protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.o


protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.o: protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/flags.make
protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.o: /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/ssl/ssl_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vagrant/Desktop/csci499_cpshanno/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.o"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/ssl && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ssl_test.dir/ssl_test.cc.o -c /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/ssl/ssl_test.cc

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ssl_test.dir/ssl_test.cc.i"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/ssl && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/ssl/ssl_test.cc > CMakeFiles/ssl_test.dir/ssl_test.cc.i

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ssl_test.dir/ssl_test.cc.s"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/ssl && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/ssl/ssl_test.cc -o CMakeFiles/ssl_test.dir/ssl_test.cc.s

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.o.requires:

.PHONY : protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.o.requires

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.o.provides: protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.o.requires
	$(MAKE) -f protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/build.make protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.o.provides.build
.PHONY : protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.o.provides

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.o.provides.build: protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.o


# Object files for target ssl_test
ssl_test_OBJECTS = \
"CMakeFiles/ssl_test.dir/span_test.cc.o" \
"CMakeFiles/ssl_test.dir/ssl_test.cc.o"

# External object files for target ssl_test
ssl_test_EXTERNAL_OBJECTS = \
"/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/test/CMakeFiles/boringssl_gtest_main.dir/gtest_main.cc.o" \
"/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/test/CMakeFiles/test_support.dir/file_test.cc.o" \
"/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/test/CMakeFiles/test_support.dir/malloc.cc.o" \
"/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/test/CMakeFiles/test_support.dir/test_util.cc.o"

bin/ssl_test: protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.o
bin/ssl_test: protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.o
bin/ssl_test: protos/grpc/third_party/boringssl/crypto/test/CMakeFiles/boringssl_gtest_main.dir/gtest_main.cc.o
bin/ssl_test: protos/grpc/third_party/boringssl/crypto/test/CMakeFiles/test_support.dir/file_test.cc.o
bin/ssl_test: protos/grpc/third_party/boringssl/crypto/test/CMakeFiles/test_support.dir/malloc.cc.o
bin/ssl_test: protos/grpc/third_party/boringssl/crypto/test/CMakeFiles/test_support.dir/test_util.cc.o
bin/ssl_test: protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/build.make
bin/ssl_test: protos/grpc/third_party/boringssl/ssl/libssl.a
bin/ssl_test: protos/grpc/third_party/boringssl/crypto/libcrypto.a
bin/ssl_test: protos/grpc/third_party/boringssl/libboringssl_gtest.a
bin/ssl_test: protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vagrant/Desktop/csci499_cpshanno/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../../../bin/ssl_test"
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/ssl && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ssl_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/build: bin/ssl_test

.PHONY : protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/build

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/requires: protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/span_test.cc.o.requires
protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/requires: protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/ssl_test.cc.o.requires

.PHONY : protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/requires

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/clean:
	cd /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/ssl && $(CMAKE_COMMAND) -P CMakeFiles/ssl_test.dir/cmake_clean.cmake
.PHONY : protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/clean

protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/depend:
	cd /home/vagrant/Desktop/csci499_cpshanno/project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/ssl /home/vagrant/Desktop/csci499_cpshanno/project /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/ssl /home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : protos/grpc/third_party/boringssl/ssl/CMakeFiles/ssl_test.dir/depend

