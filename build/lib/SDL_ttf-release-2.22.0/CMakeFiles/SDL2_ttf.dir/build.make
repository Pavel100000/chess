# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\chess\build

# Include any dependencies generated for this target.
include lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/progress.make

# Include the compile flags for this target's objects.
include lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/flags.make

lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/SDL_ttf.c.obj: lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/flags.make
lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/SDL_ttf.c.obj: lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/includes_C.rsp
lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/SDL_ttf.c.obj: C:/chess/lib/SDL_ttf-release-2.22.0/SDL_ttf.c
lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/SDL_ttf.c.obj: lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/SDL_ttf.c.obj"
	cd /d C:\chess\build\lib\SDL_ttf-release-2.22.0 && C:\chess\w64devkit\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/SDL_ttf.c.obj -MF CMakeFiles\SDL2_ttf.dir\SDL_ttf.c.obj.d -o CMakeFiles\SDL2_ttf.dir\SDL_ttf.c.obj -c C:\chess\lib\SDL_ttf-release-2.22.0\SDL_ttf.c

lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/SDL_ttf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_ttf.dir/SDL_ttf.c.i"
	cd /d C:\chess\build\lib\SDL_ttf-release-2.22.0 && C:\chess\w64devkit\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\chess\lib\SDL_ttf-release-2.22.0\SDL_ttf.c > CMakeFiles\SDL2_ttf.dir\SDL_ttf.c.i

lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/SDL_ttf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_ttf.dir/SDL_ttf.c.s"
	cd /d C:\chess\build\lib\SDL_ttf-release-2.22.0 && C:\chess\w64devkit\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\chess\lib\SDL_ttf-release-2.22.0\SDL_ttf.c -o CMakeFiles\SDL2_ttf.dir\SDL_ttf.c.s

lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/version.rc.obj: lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/flags.make
lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/version.rc.obj: C:/chess/lib/SDL_ttf-release-2.22.0/version.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/version.rc.obj"
	cd /d C:\chess\build\lib\SDL_ttf-release-2.22.0 && C:\chess\w64devkit\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) C:\chess\lib\SDL_ttf-release-2.22.0\version.rc CMakeFiles\SDL2_ttf.dir\version.rc.obj

# Object files for target SDL2_ttf
SDL2_ttf_OBJECTS = \
"CMakeFiles/SDL2_ttf.dir/SDL_ttf.c.obj" \
"CMakeFiles/SDL2_ttf.dir/version.rc.obj"

# External object files for target SDL2_ttf
SDL2_ttf_EXTERNAL_OBJECTS =

SDL2_ttf.dll: lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/SDL_ttf.c.obj
SDL2_ttf.dll: lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/version.rc.obj
SDL2_ttf.dll: lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/build.make
SDL2_ttf.dll: lib/SDL-release-2.30.3/libSDL2.dll.a
SDL2_ttf.dll: lib/SDL_ttf-release-2.22.0/external/freetype/libfreetype.a
SDL2_ttf.dll: lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/linkLibs.rsp
SDL2_ttf.dll: lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/objects1.rsp
SDL2_ttf.dll: lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C shared library ..\..\SDL2_ttf.dll"
	cd /d C:\chess\build\lib\SDL_ttf-release-2.22.0 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SDL2_ttf.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/build: SDL2_ttf.dll
.PHONY : lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/build

lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/clean:
	cd /d C:\chess\build\lib\SDL_ttf-release-2.22.0 && $(CMAKE_COMMAND) -P CMakeFiles\SDL2_ttf.dir\cmake_clean.cmake
.PHONY : lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/clean

lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\chess C:\chess\lib\SDL_ttf-release-2.22.0 C:\chess\build C:\chess\build\lib\SDL_ttf-release-2.22.0 C:\chess\build\lib\SDL_ttf-release-2.22.0\CMakeFiles\SDL2_ttf.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/SDL_ttf-release-2.22.0/CMakeFiles/SDL2_ttf.dir/depend

