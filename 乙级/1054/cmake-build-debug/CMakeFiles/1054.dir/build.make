# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/williamjing/Documents/Clion Projects/PAT/Basic Level/1054"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/williamjing/Documents/Clion Projects/PAT/Basic Level/1054/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/1054.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/1054.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/1054.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1054.dir/flags.make

CMakeFiles/1054.dir/main.cpp.o: CMakeFiles/1054.dir/flags.make
CMakeFiles/1054.dir/main.cpp.o: ../main.cpp
CMakeFiles/1054.dir/main.cpp.o: CMakeFiles/1054.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/williamjing/Documents/Clion Projects/PAT/Basic Level/1054/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1054.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/1054.dir/main.cpp.o -MF CMakeFiles/1054.dir/main.cpp.o.d -o CMakeFiles/1054.dir/main.cpp.o -c "/Users/williamjing/Documents/Clion Projects/PAT/Basic Level/1054/main.cpp"

CMakeFiles/1054.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1054.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/williamjing/Documents/Clion Projects/PAT/Basic Level/1054/main.cpp" > CMakeFiles/1054.dir/main.cpp.i

CMakeFiles/1054.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1054.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/williamjing/Documents/Clion Projects/PAT/Basic Level/1054/main.cpp" -o CMakeFiles/1054.dir/main.cpp.s

# Object files for target 1054
1054_OBJECTS = \
"CMakeFiles/1054.dir/main.cpp.o"

# External object files for target 1054
1054_EXTERNAL_OBJECTS =

1054: CMakeFiles/1054.dir/main.cpp.o
1054: CMakeFiles/1054.dir/build.make
1054: CMakeFiles/1054.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/williamjing/Documents/Clion Projects/PAT/Basic Level/1054/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1054"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1054.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1054.dir/build: 1054
.PHONY : CMakeFiles/1054.dir/build

CMakeFiles/1054.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1054.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1054.dir/clean

CMakeFiles/1054.dir/depend:
	cd "/Users/williamjing/Documents/Clion Projects/PAT/Basic Level/1054/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/williamjing/Documents/Clion Projects/PAT/Basic Level/1054" "/Users/williamjing/Documents/Clion Projects/PAT/Basic Level/1054" "/Users/williamjing/Documents/Clion Projects/PAT/Basic Level/1054/cmake-build-debug" "/Users/williamjing/Documents/Clion Projects/PAT/Basic Level/1054/cmake-build-debug" "/Users/williamjing/Documents/Clion Projects/PAT/Basic Level/1054/cmake-build-debug/CMakeFiles/1054.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/1054.dir/depend

