# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /home/luca/projects/ImageManipulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luca/projects/ImageManipulator/build

# Include any dependencies generated for this target.
include CMakeFiles/ImageManipulator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ImageManipulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ImageManipulator.dir/flags.make

CMakeFiles/ImageManipulator.dir/Source/Main.cpp.o: CMakeFiles/ImageManipulator.dir/flags.make
CMakeFiles/ImageManipulator.dir/Source/Main.cpp.o: ../Source/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luca/projects/ImageManipulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ImageManipulator.dir/Source/Main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImageManipulator.dir/Source/Main.cpp.o -c /home/luca/projects/ImageManipulator/Source/Main.cpp

CMakeFiles/ImageManipulator.dir/Source/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageManipulator.dir/Source/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luca/projects/ImageManipulator/Source/Main.cpp > CMakeFiles/ImageManipulator.dir/Source/Main.cpp.i

CMakeFiles/ImageManipulator.dir/Source/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageManipulator.dir/Source/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luca/projects/ImageManipulator/Source/Main.cpp -o CMakeFiles/ImageManipulator.dir/Source/Main.cpp.s

# Object files for target ImageManipulator
ImageManipulator_OBJECTS = \
"CMakeFiles/ImageManipulator.dir/Source/Main.cpp.o"

# External object files for target ImageManipulator
ImageManipulator_EXTERNAL_OBJECTS =

../Bin/ImageManipulator: CMakeFiles/ImageManipulator.dir/Source/Main.cpp.o
../Bin/ImageManipulator: CMakeFiles/ImageManipulator.dir/build.make
../Bin/ImageManipulator: /usr/local/lib/libGorgon.a
../Bin/ImageManipulator: /usr/lib64/libGL.so
../Bin/ImageManipulator: /usr/lib64/libGLU.so
../Bin/ImageManipulator: /usr/lib64/libfreetype.so
../Bin/ImageManipulator: /usr/lib64/libSM.so
../Bin/ImageManipulator: /usr/lib64/libICE.so
../Bin/ImageManipulator: /usr/lib64/libX11.so
../Bin/ImageManipulator: /usr/lib64/libXext.so
../Bin/ImageManipulator: /usr/lib64/libXrandr.so
../Bin/ImageManipulator: /usr/lib64/libXinerama.so
../Bin/ImageManipulator: /usr/lib64/libpulse.so
../Bin/ImageManipulator: /usr/local/lib/libflac.a
../Bin/ImageManipulator: CMakeFiles/ImageManipulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luca/projects/ImageManipulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../Bin/ImageManipulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ImageManipulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ImageManipulator.dir/build: ../Bin/ImageManipulator

.PHONY : CMakeFiles/ImageManipulator.dir/build

CMakeFiles/ImageManipulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ImageManipulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ImageManipulator.dir/clean

CMakeFiles/ImageManipulator.dir/depend:
	cd /home/luca/projects/ImageManipulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luca/projects/ImageManipulator /home/luca/projects/ImageManipulator /home/luca/projects/ImageManipulator/build /home/luca/projects/ImageManipulator/build /home/luca/projects/ImageManipulator/build/CMakeFiles/ImageManipulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ImageManipulator.dir/depend
