# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /Users/reebdeve/CLionProjects/CatLog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/reebdeve/CLionProjects/CatLog/cmake-build-debug

# Include any dependencies generated for this target.
include leveldb/CMakeFiles/leveldbutil.dir/depend.make
# Include the progress variables for this target.
include leveldb/CMakeFiles/leveldbutil.dir/progress.make

# Include the compile flags for this target's objects.
include leveldb/CMakeFiles/leveldbutil.dir/flags.make

leveldb/CMakeFiles/leveldbutil.dir/db/leveldbutil.cc.o: leveldb/CMakeFiles/leveldbutil.dir/flags.make
leveldb/CMakeFiles/leveldbutil.dir/db/leveldbutil.cc.o: ../leveldb/db/leveldbutil.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/reebdeve/CLionProjects/CatLog/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object leveldb/CMakeFiles/leveldbutil.dir/db/leveldbutil.cc.o"
	cd /Users/reebdeve/CLionProjects/CatLog/cmake-build-debug/leveldb && /opt/homebrew/Cellar/gcc/11.2.0/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/leveldbutil.dir/db/leveldbutil.cc.o -c /Users/reebdeve/CLionProjects/CatLog/leveldb/db/leveldbutil.cc

leveldb/CMakeFiles/leveldbutil.dir/db/leveldbutil.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/leveldbutil.dir/db/leveldbutil.cc.i"
	cd /Users/reebdeve/CLionProjects/CatLog/cmake-build-debug/leveldb && /opt/homebrew/Cellar/gcc/11.2.0/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/reebdeve/CLionProjects/CatLog/leveldb/db/leveldbutil.cc > CMakeFiles/leveldbutil.dir/db/leveldbutil.cc.i

leveldb/CMakeFiles/leveldbutil.dir/db/leveldbutil.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/leveldbutil.dir/db/leveldbutil.cc.s"
	cd /Users/reebdeve/CLionProjects/CatLog/cmake-build-debug/leveldb && /opt/homebrew/Cellar/gcc/11.2.0/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/reebdeve/CLionProjects/CatLog/leveldb/db/leveldbutil.cc -o CMakeFiles/leveldbutil.dir/db/leveldbutil.cc.s

# Object files for target leveldbutil
leveldbutil_OBJECTS = \
"CMakeFiles/leveldbutil.dir/db/leveldbutil.cc.o"

# External object files for target leveldbutil
leveldbutil_EXTERNAL_OBJECTS =

leveldb/leveldbutil: leveldb/CMakeFiles/leveldbutil.dir/db/leveldbutil.cc.o
leveldb/leveldbutil: leveldb/CMakeFiles/leveldbutil.dir/build.make
leveldb/leveldbutil: leveldb/libleveldb.a
leveldb/leveldbutil: leveldb/CMakeFiles/leveldbutil.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/reebdeve/CLionProjects/CatLog/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable leveldbutil"
	cd /Users/reebdeve/CLionProjects/CatLog/cmake-build-debug/leveldb && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/leveldbutil.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
leveldb/CMakeFiles/leveldbutil.dir/build: leveldb/leveldbutil
.PHONY : leveldb/CMakeFiles/leveldbutil.dir/build

leveldb/CMakeFiles/leveldbutil.dir/clean:
	cd /Users/reebdeve/CLionProjects/CatLog/cmake-build-debug/leveldb && $(CMAKE_COMMAND) -P CMakeFiles/leveldbutil.dir/cmake_clean.cmake
.PHONY : leveldb/CMakeFiles/leveldbutil.dir/clean

leveldb/CMakeFiles/leveldbutil.dir/depend:
	cd /Users/reebdeve/CLionProjects/CatLog/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/reebdeve/CLionProjects/CatLog /Users/reebdeve/CLionProjects/CatLog/leveldb /Users/reebdeve/CLionProjects/CatLog/cmake-build-debug /Users/reebdeve/CLionProjects/CatLog/cmake-build-debug/leveldb /Users/reebdeve/CLionProjects/CatLog/cmake-build-debug/leveldb/CMakeFiles/leveldbutil.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : leveldb/CMakeFiles/leveldbutil.dir/depend

