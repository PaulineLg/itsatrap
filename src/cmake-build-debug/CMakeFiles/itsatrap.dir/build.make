# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/itsatrap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/itsatrap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/itsatrap.dir/flags.make

CMakeFiles/itsatrap.dir/main.obj: CMakeFiles/itsatrap.dir/flags.make
CMakeFiles/itsatrap.dir/main.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/itsatrap.dir/main.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\itsatrap.dir\main.obj -c "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\main.cpp"

CMakeFiles/itsatrap.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/itsatrap.dir/main.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\main.cpp" > CMakeFiles\itsatrap.dir\main.i

CMakeFiles/itsatrap.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/itsatrap.dir/main.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\main.cpp" -o CMakeFiles\itsatrap.dir\main.s

CMakeFiles/itsatrap.dir/main.obj.requires:

.PHONY : CMakeFiles/itsatrap.dir/main.obj.requires

CMakeFiles/itsatrap.dir/main.obj.provides: CMakeFiles/itsatrap.dir/main.obj.requires
	$(MAKE) -f CMakeFiles\itsatrap.dir\build.make CMakeFiles/itsatrap.dir/main.obj.provides.build
.PHONY : CMakeFiles/itsatrap.dir/main.obj.provides

CMakeFiles/itsatrap.dir/main.obj.provides.build: CMakeFiles/itsatrap.dir/main.obj


CMakeFiles/itsatrap.dir/GAME/game.obj: CMakeFiles/itsatrap.dir/flags.make
CMakeFiles/itsatrap.dir/GAME/game.obj: ../GAME/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/itsatrap.dir/GAME/game.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\itsatrap.dir\GAME\game.obj -c "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\GAME\game.cpp"

CMakeFiles/itsatrap.dir/GAME/game.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/itsatrap.dir/GAME/game.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\GAME\game.cpp" > CMakeFiles\itsatrap.dir\GAME\game.i

CMakeFiles/itsatrap.dir/GAME/game.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/itsatrap.dir/GAME/game.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\GAME\game.cpp" -o CMakeFiles\itsatrap.dir\GAME\game.s

CMakeFiles/itsatrap.dir/GAME/game.obj.requires:

.PHONY : CMakeFiles/itsatrap.dir/GAME/game.obj.requires

CMakeFiles/itsatrap.dir/GAME/game.obj.provides: CMakeFiles/itsatrap.dir/GAME/game.obj.requires
	$(MAKE) -f CMakeFiles\itsatrap.dir\build.make CMakeFiles/itsatrap.dir/GAME/game.obj.provides.build
.PHONY : CMakeFiles/itsatrap.dir/GAME/game.obj.provides

CMakeFiles/itsatrap.dir/GAME/game.obj.provides.build: CMakeFiles/itsatrap.dir/GAME/game.obj


CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj: CMakeFiles/itsatrap.dir/flags.make
CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj: ../GAMESTATE/titlestate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\itsatrap.dir\GAMESTATE\titlestate.obj -c "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\GAMESTATE\titlestate.cpp"

CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\GAMESTATE\titlestate.cpp" > CMakeFiles\itsatrap.dir\GAMESTATE\titlestate.i

CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\GAMESTATE\titlestate.cpp" -o CMakeFiles\itsatrap.dir\GAMESTATE\titlestate.s

CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj.requires:

.PHONY : CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj.requires

CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj.provides: CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj.requires
	$(MAKE) -f CMakeFiles\itsatrap.dir\build.make CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj.provides.build
.PHONY : CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj.provides

CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj.provides.build: CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj


CMakeFiles/itsatrap.dir/OBJECT/object.obj: CMakeFiles/itsatrap.dir/flags.make
CMakeFiles/itsatrap.dir/OBJECT/object.obj: ../OBJECT/object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/itsatrap.dir/OBJECT/object.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\itsatrap.dir\OBJECT\object.obj -c "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\OBJECT\object.cpp"

CMakeFiles/itsatrap.dir/OBJECT/object.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/itsatrap.dir/OBJECT/object.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\OBJECT\object.cpp" > CMakeFiles\itsatrap.dir\OBJECT\object.i

CMakeFiles/itsatrap.dir/OBJECT/object.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/itsatrap.dir/OBJECT/object.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\OBJECT\object.cpp" -o CMakeFiles\itsatrap.dir\OBJECT\object.s

CMakeFiles/itsatrap.dir/OBJECT/object.obj.requires:

.PHONY : CMakeFiles/itsatrap.dir/OBJECT/object.obj.requires

CMakeFiles/itsatrap.dir/OBJECT/object.obj.provides: CMakeFiles/itsatrap.dir/OBJECT/object.obj.requires
	$(MAKE) -f CMakeFiles\itsatrap.dir\build.make CMakeFiles/itsatrap.dir/OBJECT/object.obj.provides.build
.PHONY : CMakeFiles/itsatrap.dir/OBJECT/object.obj.provides

CMakeFiles/itsatrap.dir/OBJECT/object.obj.provides.build: CMakeFiles/itsatrap.dir/OBJECT/object.obj


# Object files for target itsatrap
itsatrap_OBJECTS = \
"CMakeFiles/itsatrap.dir/main.obj" \
"CMakeFiles/itsatrap.dir/GAME/game.obj" \
"CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj" \
"CMakeFiles/itsatrap.dir/OBJECT/object.obj"

# External object files for target itsatrap
itsatrap_EXTERNAL_OBJECTS =

itsatrap.exe: CMakeFiles/itsatrap.dir/main.obj
itsatrap.exe: CMakeFiles/itsatrap.dir/GAME/game.obj
itsatrap.exe: CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj
itsatrap.exe: CMakeFiles/itsatrap.dir/OBJECT/object.obj
itsatrap.exe: CMakeFiles/itsatrap.dir/build.make
itsatrap.exe: CMakeFiles/itsatrap.dir/linklibs.rsp
itsatrap.exe: CMakeFiles/itsatrap.dir/objects1.rsp
itsatrap.exe: CMakeFiles/itsatrap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable itsatrap.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\itsatrap.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/itsatrap.dir/build: itsatrap.exe

.PHONY : CMakeFiles/itsatrap.dir/build

CMakeFiles/itsatrap.dir/requires: CMakeFiles/itsatrap.dir/main.obj.requires
CMakeFiles/itsatrap.dir/requires: CMakeFiles/itsatrap.dir/GAME/game.obj.requires
CMakeFiles/itsatrap.dir/requires: CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.obj.requires
CMakeFiles/itsatrap.dir/requires: CMakeFiles/itsatrap.dir/OBJECT/object.obj.requires

.PHONY : CMakeFiles/itsatrap.dir/requires

CMakeFiles/itsatrap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\itsatrap.dir\cmake_clean.cmake
.PHONY : CMakeFiles/itsatrap.dir/clean

CMakeFiles/itsatrap.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src" "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src" "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\cmake-build-debug" "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\cmake-build-debug" "D:\Documents\Cours\IMAC 2\Pacman\itsatrap\src\cmake-build-debug\CMakeFiles\itsatrap.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/itsatrap.dir/depend

