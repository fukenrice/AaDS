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
CMAKE_SOURCE_DIR = /mnt/d/University_CXX/Algorithms/Contest_16+

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/University_CXX/Algorithms/Contest_16+/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Contest_16+.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Contest_16+.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Contest_16+.dir/flags.make

CMakeFiles/Contest_16+.dir/Contest_17/Task_3.cpp.o: CMakeFiles/Contest_16+.dir/flags.make
CMakeFiles/Contest_16+.dir/Contest_17/Task_3.cpp.o: ../Contest_17/Task_3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/University_CXX/Algorithms/Contest_16+/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Contest_16+.dir/Contest_17/Task_3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Contest_16+.dir/Contest_17/Task_3.cpp.o -c /mnt/d/University_CXX/Algorithms/Contest_16+/Contest_17/Task_3.cpp

CMakeFiles/Contest_16+.dir/Contest_17/Task_3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Contest_16+.dir/Contest_17/Task_3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/University_CXX/Algorithms/Contest_16+/Contest_17/Task_3.cpp > CMakeFiles/Contest_16+.dir/Contest_17/Task_3.cpp.i

CMakeFiles/Contest_16+.dir/Contest_17/Task_3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Contest_16+.dir/Contest_17/Task_3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/University_CXX/Algorithms/Contest_16+/Contest_17/Task_3.cpp -o CMakeFiles/Contest_16+.dir/Contest_17/Task_3.cpp.s

# Object files for target Contest_16+
Contest_16____OBJECTS = \
"CMakeFiles/Contest_16+.dir/Contest_17/Task_3.cpp.o"

# External object files for target Contest_16+
Contest_16____EXTERNAL_OBJECTS =

Contest_16+: CMakeFiles/Contest_16+.dir/Contest_17/Task_3.cpp.o
Contest_16+: CMakeFiles/Contest_16+.dir/build.make
Contest_16+: CMakeFiles/Contest_16+.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/University_CXX/Algorithms/Contest_16+/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Contest_16+"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Contest_16+.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Contest_16+.dir/build: Contest_16+

.PHONY : CMakeFiles/Contest_16+.dir/build

CMakeFiles/Contest_16+.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Contest_16+.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Contest_16+.dir/clean

CMakeFiles/Contest_16+.dir/depend:
	cd /mnt/d/University_CXX/Algorithms/Contest_16+/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/University_CXX/Algorithms/Contest_16+ /mnt/d/University_CXX/Algorithms/Contest_16+ /mnt/d/University_CXX/Algorithms/Contest_16+/cmake-build-debug /mnt/d/University_CXX/Algorithms/Contest_16+/cmake-build-debug /mnt/d/University_CXX/Algorithms/Contest_16+/cmake-build-debug/CMakeFiles/Contest_16+.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Contest_16+.dir/depend

