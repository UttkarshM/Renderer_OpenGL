# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/uttkarsh/OpenGL_Library/OpenGL_library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uttkarsh/OpenGL_Library/OpenGL_library/build

# Utility rule file for update_mappings.

# Include any custom commands dependencies for this target.
include external/glfw/src/CMakeFiles/update_mappings.dir/compiler_depend.make

# Include the progress variables for this target.
include external/glfw/src/CMakeFiles/update_mappings.dir/progress.make

external/glfw/src/CMakeFiles/update_mappings:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/uttkarsh/OpenGL_Library/OpenGL_library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Updating gamepad mappings from upstream repository"
	cd /home/uttkarsh/OpenGL_Library/OpenGL_library/external/glfw/src && /usr/bin/cmake -P /home/uttkarsh/OpenGL_Library/OpenGL_library/external/glfw/CMake/GenerateMappings.cmake mappings.h.in mappings.h

update_mappings: external/glfw/src/CMakeFiles/update_mappings
update_mappings: external/glfw/src/CMakeFiles/update_mappings.dir/build.make
.PHONY : update_mappings

# Rule to build all files generated by this target.
external/glfw/src/CMakeFiles/update_mappings.dir/build: update_mappings
.PHONY : external/glfw/src/CMakeFiles/update_mappings.dir/build

external/glfw/src/CMakeFiles/update_mappings.dir/clean:
	cd /home/uttkarsh/OpenGL_Library/OpenGL_library/build/external/glfw/src && $(CMAKE_COMMAND) -P CMakeFiles/update_mappings.dir/cmake_clean.cmake
.PHONY : external/glfw/src/CMakeFiles/update_mappings.dir/clean

external/glfw/src/CMakeFiles/update_mappings.dir/depend:
	cd /home/uttkarsh/OpenGL_Library/OpenGL_library/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uttkarsh/OpenGL_Library/OpenGL_library /home/uttkarsh/OpenGL_Library/OpenGL_library/external/glfw/src /home/uttkarsh/OpenGL_Library/OpenGL_library/build /home/uttkarsh/OpenGL_Library/OpenGL_library/build/external/glfw/src /home/uttkarsh/OpenGL_Library/OpenGL_library/build/external/glfw/src/CMakeFiles/update_mappings.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : external/glfw/src/CMakeFiles/update_mappings.dir/depend

