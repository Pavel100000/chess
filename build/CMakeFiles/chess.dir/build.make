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
include CMakeFiles/chess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chess.dir/flags.make

CMakeFiles/chess.dir/src/bitboards.c.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/bitboards.c.obj: CMakeFiles/chess.dir/includes_C.rsp
CMakeFiles/chess.dir/src/bitboards.c.obj: C:/chess/src/bitboards.c
CMakeFiles/chess.dir/src/bitboards.c.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/chess.dir/src/bitboards.c.obj"
	C:\chess\w64devkit\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/chess.dir/src/bitboards.c.obj -MF CMakeFiles\chess.dir\src\bitboards.c.obj.d -o CMakeFiles\chess.dir\src\bitboards.c.obj -c C:\chess\src\bitboards.c

CMakeFiles/chess.dir/src/bitboards.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/chess.dir/src/bitboards.c.i"
	C:\chess\w64devkit\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\chess\src\bitboards.c > CMakeFiles\chess.dir\src\bitboards.c.i

CMakeFiles/chess.dir/src/bitboards.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/chess.dir/src/bitboards.c.s"
	C:\chess\w64devkit\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\chess\src\bitboards.c -o CMakeFiles\chess.dir\src\bitboards.c.s

CMakeFiles/chess.dir/src/gameplay.c.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/gameplay.c.obj: CMakeFiles/chess.dir/includes_C.rsp
CMakeFiles/chess.dir/src/gameplay.c.obj: C:/chess/src/gameplay.c
CMakeFiles/chess.dir/src/gameplay.c.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/chess.dir/src/gameplay.c.obj"
	C:\chess\w64devkit\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/chess.dir/src/gameplay.c.obj -MF CMakeFiles\chess.dir\src\gameplay.c.obj.d -o CMakeFiles\chess.dir\src\gameplay.c.obj -c C:\chess\src\gameplay.c

CMakeFiles/chess.dir/src/gameplay.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/chess.dir/src/gameplay.c.i"
	C:\chess\w64devkit\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\chess\src\gameplay.c > CMakeFiles\chess.dir\src\gameplay.c.i

CMakeFiles/chess.dir/src/gameplay.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/chess.dir/src/gameplay.c.s"
	C:\chess\w64devkit\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\chess\src\gameplay.c -o CMakeFiles\chess.dir\src\gameplay.c.s

CMakeFiles/chess.dir/src/rules2ver.c.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/rules2ver.c.obj: CMakeFiles/chess.dir/includes_C.rsp
CMakeFiles/chess.dir/src/rules2ver.c.obj: C:/chess/src/rules2ver.c
CMakeFiles/chess.dir/src/rules2ver.c.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/chess.dir/src/rules2ver.c.obj"
	C:\chess\w64devkit\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/chess.dir/src/rules2ver.c.obj -MF CMakeFiles\chess.dir\src\rules2ver.c.obj.d -o CMakeFiles\chess.dir\src\rules2ver.c.obj -c C:\chess\src\rules2ver.c

CMakeFiles/chess.dir/src/rules2ver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/chess.dir/src/rules2ver.c.i"
	C:\chess\w64devkit\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\chess\src\rules2ver.c > CMakeFiles\chess.dir\src\rules2ver.c.i

CMakeFiles/chess.dir/src/rules2ver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/chess.dir/src/rules2ver.c.s"
	C:\chess\w64devkit\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\chess\src\rules2ver.c -o CMakeFiles\chess.dir\src\rules2ver.c.s

# Object files for target chess
chess_OBJECTS = \
"CMakeFiles/chess.dir/src/bitboards.c.obj" \
"CMakeFiles/chess.dir/src/gameplay.c.obj" \
"CMakeFiles/chess.dir/src/rules2ver.c.obj"

# External object files for target chess
chess_EXTERNAL_OBJECTS =

chess.exe: CMakeFiles/chess.dir/src/bitboards.c.obj
chess.exe: CMakeFiles/chess.dir/src/gameplay.c.obj
chess.exe: CMakeFiles/chess.dir/src/rules2ver.c.obj
chess.exe: CMakeFiles/chess.dir/build.make
chess.exe: CMakeFiles/chess.dir/linkLibs.rsp
chess.exe: CMakeFiles/chess.dir/objects1.rsp
chess.exe: CMakeFiles/chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable chess.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\chess.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chess.dir/build: chess.exe
.PHONY : CMakeFiles/chess.dir/build

CMakeFiles/chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\chess.dir\cmake_clean.cmake
.PHONY : CMakeFiles/chess.dir/clean

CMakeFiles/chess.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\chess C:\chess C:\chess\build C:\chess\build C:\chess\build\CMakeFiles\chess.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/chess.dir/depend
