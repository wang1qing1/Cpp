# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wq/24_06_06/demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wq/24_06_06/demo

# Include any dependencies generated for this target.
include test1/CMakeFiles/test_sort.dir/depend.make

# Include the progress variables for this target.
include test1/CMakeFiles/test_sort.dir/progress.make

# Include the compile flags for this target's objects.
include test1/CMakeFiles/test_sort.dir/flags.make

test1/CMakeFiles/test_sort.dir/sort.cpp.o: test1/CMakeFiles/test_sort.dir/flags.make
test1/CMakeFiles/test_sort.dir/sort.cpp.o: test1/sort.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/wq/24_06_06/demo/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test1/CMakeFiles/test_sort.dir/sort.cpp.o"
	cd /home/wq/24_06_06/demo/test1 && /opt/rh/devtoolset-7/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_sort.dir/sort.cpp.o -c /home/wq/24_06_06/demo/test1/sort.cpp

test1/CMakeFiles/test_sort.dir/sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_sort.dir/sort.cpp.i"
	cd /home/wq/24_06_06/demo/test1 && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/wq/24_06_06/demo/test1/sort.cpp > CMakeFiles/test_sort.dir/sort.cpp.i

test1/CMakeFiles/test_sort.dir/sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_sort.dir/sort.cpp.s"
	cd /home/wq/24_06_06/demo/test1 && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/wq/24_06_06/demo/test1/sort.cpp -o CMakeFiles/test_sort.dir/sort.cpp.s

test1/CMakeFiles/test_sort.dir/sort.cpp.o.requires:
.PHONY : test1/CMakeFiles/test_sort.dir/sort.cpp.o.requires

test1/CMakeFiles/test_sort.dir/sort.cpp.o.provides: test1/CMakeFiles/test_sort.dir/sort.cpp.o.requires
	$(MAKE) -f test1/CMakeFiles/test_sort.dir/build.make test1/CMakeFiles/test_sort.dir/sort.cpp.o.provides.build
.PHONY : test1/CMakeFiles/test_sort.dir/sort.cpp.o.provides

test1/CMakeFiles/test_sort.dir/sort.cpp.o.provides.build: test1/CMakeFiles/test_sort.dir/sort.cpp.o

# Object files for target test_sort
test_sort_OBJECTS = \
"CMakeFiles/test_sort.dir/sort.cpp.o"

# External object files for target test_sort
test_sort_EXTERNAL_OBJECTS =

out/test_sort: test1/CMakeFiles/test_sort.dir/sort.cpp.o
out/test_sort: test1/CMakeFiles/test_sort.dir/build.make
out/test_sort: lib/libsort.a
out/test_sort: test1/CMakeFiles/test_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../out/test_sort"
	cd /home/wq/24_06_06/demo/test1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test1/CMakeFiles/test_sort.dir/build: out/test_sort
.PHONY : test1/CMakeFiles/test_sort.dir/build

test1/CMakeFiles/test_sort.dir/requires: test1/CMakeFiles/test_sort.dir/sort.cpp.o.requires
.PHONY : test1/CMakeFiles/test_sort.dir/requires

test1/CMakeFiles/test_sort.dir/clean:
	cd /home/wq/24_06_06/demo/test1 && $(CMAKE_COMMAND) -P CMakeFiles/test_sort.dir/cmake_clean.cmake
.PHONY : test1/CMakeFiles/test_sort.dir/clean

test1/CMakeFiles/test_sort.dir/depend:
	cd /home/wq/24_06_06/demo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wq/24_06_06/demo /home/wq/24_06_06/demo/test1 /home/wq/24_06_06/demo /home/wq/24_06_06/demo/test1 /home/wq/24_06_06/demo/test1/CMakeFiles/test_sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test1/CMakeFiles/test_sort.dir/depend

