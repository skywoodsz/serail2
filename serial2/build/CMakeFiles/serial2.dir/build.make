# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/skywoodsz/racecar_test/program/serial2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/skywoodsz/racecar_test/program/serial2/build

# Include any dependencies generated for this target.
include CMakeFiles/serial2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/serial2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serial2.dir/flags.make

CMakeFiles/serial2.dir/main.cpp.o: CMakeFiles/serial2.dir/flags.make
CMakeFiles/serial2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/skywoodsz/racecar_test/program/serial2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/serial2.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serial2.dir/main.cpp.o -c /home/skywoodsz/racecar_test/program/serial2/main.cpp

CMakeFiles/serial2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial2.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/skywoodsz/racecar_test/program/serial2/main.cpp > CMakeFiles/serial2.dir/main.cpp.i

CMakeFiles/serial2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial2.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/skywoodsz/racecar_test/program/serial2/main.cpp -o CMakeFiles/serial2.dir/main.cpp.s

CMakeFiles/serial2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/serial2.dir/main.cpp.o.requires

CMakeFiles/serial2.dir/main.cpp.o.provides: CMakeFiles/serial2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/serial2.dir/build.make CMakeFiles/serial2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/serial2.dir/main.cpp.o.provides

CMakeFiles/serial2.dir/main.cpp.o.provides.build: CMakeFiles/serial2.dir/main.cpp.o


CMakeFiles/serial2.dir/pc2mcu.cpp.o: CMakeFiles/serial2.dir/flags.make
CMakeFiles/serial2.dir/pc2mcu.cpp.o: ../pc2mcu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/skywoodsz/racecar_test/program/serial2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/serial2.dir/pc2mcu.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serial2.dir/pc2mcu.cpp.o -c /home/skywoodsz/racecar_test/program/serial2/pc2mcu.cpp

CMakeFiles/serial2.dir/pc2mcu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial2.dir/pc2mcu.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/skywoodsz/racecar_test/program/serial2/pc2mcu.cpp > CMakeFiles/serial2.dir/pc2mcu.cpp.i

CMakeFiles/serial2.dir/pc2mcu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial2.dir/pc2mcu.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/skywoodsz/racecar_test/program/serial2/pc2mcu.cpp -o CMakeFiles/serial2.dir/pc2mcu.cpp.s

CMakeFiles/serial2.dir/pc2mcu.cpp.o.requires:

.PHONY : CMakeFiles/serial2.dir/pc2mcu.cpp.o.requires

CMakeFiles/serial2.dir/pc2mcu.cpp.o.provides: CMakeFiles/serial2.dir/pc2mcu.cpp.o.requires
	$(MAKE) -f CMakeFiles/serial2.dir/build.make CMakeFiles/serial2.dir/pc2mcu.cpp.o.provides.build
.PHONY : CMakeFiles/serial2.dir/pc2mcu.cpp.o.provides

CMakeFiles/serial2.dir/pc2mcu.cpp.o.provides.build: CMakeFiles/serial2.dir/pc2mcu.cpp.o


# Object files for target serial2
serial2_OBJECTS = \
"CMakeFiles/serial2.dir/main.cpp.o" \
"CMakeFiles/serial2.dir/pc2mcu.cpp.o"

# External object files for target serial2
serial2_EXTERNAL_OBJECTS =

serial2: CMakeFiles/serial2.dir/main.cpp.o
serial2: CMakeFiles/serial2.dir/pc2mcu.cpp.o
serial2: CMakeFiles/serial2.dir/build.make
serial2: /usr/local/lib/libboost_system.so
serial2: /usr/local/lib/libboost_thread.so
serial2: /usr/local/lib/libboost_regex.so
serial2: /usr/local/lib/libboost_serialization.so
serial2: /usr/lib/x86_64-linux-gnu/libpthread.so
serial2: CMakeFiles/serial2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/skywoodsz/racecar_test/program/serial2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable serial2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serial2.dir/build: serial2

.PHONY : CMakeFiles/serial2.dir/build

CMakeFiles/serial2.dir/requires: CMakeFiles/serial2.dir/main.cpp.o.requires
CMakeFiles/serial2.dir/requires: CMakeFiles/serial2.dir/pc2mcu.cpp.o.requires

.PHONY : CMakeFiles/serial2.dir/requires

CMakeFiles/serial2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serial2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serial2.dir/clean

CMakeFiles/serial2.dir/depend:
	cd /home/skywoodsz/racecar_test/program/serial2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/skywoodsz/racecar_test/program/serial2 /home/skywoodsz/racecar_test/program/serial2 /home/skywoodsz/racecar_test/program/serial2/build /home/skywoodsz/racecar_test/program/serial2/build /home/skywoodsz/racecar_test/program/serial2/build/CMakeFiles/serial2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/serial2.dir/depend
