# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/d/University_CXX/Algorithms/Contest_13

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/University_CXX/Algorithms/Contest_13/cmake-build-asan

# Include any dependencies generated for this target.
include CMakeFiles/Contest_13.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Contest_13.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Contest_13.dir/flags.make

CMakeFiles/Contest_13.dir/Task_6.cpp.o: CMakeFiles/Contest_13.dir/flags.make
CMakeFiles/Contest_13.dir/Task_6.cpp.o: ../Task_6.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/University_CXX/Algorithms/Contest_13/cmake-build-asan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Contest_13.dir/Task_6.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Contest_13.dir/Task_6.cpp.o -c /mnt/d/University_CXX/Algorithms/Contest_13/Task_6.cpp

CMakeFiles/Contest_13.dir/Task_6.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Contest_13.dir/Task_6.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/University_CXX/Algorithms/Contest_13/Task_6.cpp > CMakeFiles/Contest_13.dir/Task_6.cpp.i

CMakeFiles/Contest_13.dir/Task_6.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Contest_13.dir/Task_6.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/University_CXX/Algorithms/Contest_13/Task_6.cpp -o CMakeFiles/Contest_13.dir/Task_6.cpp.s

# Object files for target Contest_13
Contest_13_OBJECTS = \
"CMakeFiles/Contest_13.dir/Task_6.cpp.o"

# External object files for target Contest_13
Contest_13_EXTERNAL_OBJECTS =

Contest_13: CMakeFiles/Contest_13.dir/Task_6.cpp.o
Contest_13: CMakeFiles/Contest_13.dir/build.make
Contest_13: CMakeFiles/Contest_13.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/University_CXX/Algorithms/Contest_13/cmake-build-asan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Contest_13"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Contest_13.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Contest_13.dir/build: Contest_13

.PHONY : CMakeFiles/Contest_13.dir/build

CMakeFiles/Contest_13.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Contest_13.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Contest_13.dir/clean

CMakeFiles/Contest_13.dir/depend:
	cd /mnt/d/University_CXX/Algorithms/Contest_13/cmake-build-asan && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/University_CXX/Algorithms/Contest_13 /mnt/d/University_CXX/Algorithms/Contest_13 /mnt/d/University_CXX/Algorithms/Contest_13/cmake-build-asan /mnt/d/University_CXX/Algorithms/Contest_13/cmake-build-asan /mnt/d/University_CXX/Algorithms/Contest_13/cmake-build-asan/CMakeFiles/Contest_13.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Contest_13.dir/depend

