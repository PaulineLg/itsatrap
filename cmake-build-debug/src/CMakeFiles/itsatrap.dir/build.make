# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = C:\Users\Ugo\Documents\IMAC\itsatrap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/itsatrap.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/itsatrap.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/itsatrap.dir/flags.make

src/CMakeFiles/itsatrap.dir/main.cpp.obj: src/CMakeFiles/itsatrap.dir/flags.make
src/CMakeFiles/itsatrap.dir/main.cpp.obj: src/CMakeFiles/itsatrap.dir/includes_CXX.rsp
src/CMakeFiles/itsatrap.dir/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/itsatrap.dir/main.cpp.obj"
	cd /d C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\itsatrap.dir\main.cpp.obj -c C:\Users\Ugo\Documents\IMAC\itsatrap\src\main.cpp

src/CMakeFiles/itsatrap.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/itsatrap.dir/main.cpp.i"
	cd /d C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ugo\Documents\IMAC\itsatrap\src\main.cpp > CMakeFiles\itsatrap.dir\main.cpp.i

src/CMakeFiles/itsatrap.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/itsatrap.dir/main.cpp.s"
	cd /d C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ugo\Documents\IMAC\itsatrap\src\main.cpp -o CMakeFiles\itsatrap.dir\main.cpp.s

src/CMakeFiles/itsatrap.dir/main.cpp.obj.requires:

.PHONY : src/CMakeFiles/itsatrap.dir/main.cpp.obj.requires

src/CMakeFiles/itsatrap.dir/main.cpp.obj.provides: src/CMakeFiles/itsatrap.dir/main.cpp.obj.requires
	$(MAKE) -f src\CMakeFiles\itsatrap.dir\build.make src/CMakeFiles/itsatrap.dir/main.cpp.obj.provides.build
.PHONY : src/CMakeFiles/itsatrap.dir/main.cpp.obj.provides

src/CMakeFiles/itsatrap.dir/main.cpp.obj.provides.build: src/CMakeFiles/itsatrap.dir/main.cpp.obj


src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj: src/CMakeFiles/itsatrap.dir/flags.make
src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj: src/CMakeFiles/itsatrap.dir/includes_CXX.rsp
src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj: ../src/GAME/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj"
	cd /d C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\itsatrap.dir\GAME\game.cpp.obj -c C:\Users\Ugo\Documents\IMAC\itsatrap\src\GAME\game.cpp

src/CMakeFiles/itsatrap.dir/GAME/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/itsatrap.dir/GAME/game.cpp.i"
	cd /d C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ugo\Documents\IMAC\itsatrap\src\GAME\game.cpp > CMakeFiles\itsatrap.dir\GAME\game.cpp.i

src/CMakeFiles/itsatrap.dir/GAME/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/itsatrap.dir/GAME/game.cpp.s"
	cd /d C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ugo\Documents\IMAC\itsatrap\src\GAME\game.cpp -o CMakeFiles\itsatrap.dir\GAME\game.cpp.s

src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj.requires:

.PHONY : src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj.requires

src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj.provides: src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj.requires
	$(MAKE) -f src\CMakeFiles\itsatrap.dir\build.make src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj.provides.build
.PHONY : src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj.provides

src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj.provides.build: src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj


src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj: src/CMakeFiles/itsatrap.dir/flags.make
src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj: src/CMakeFiles/itsatrap.dir/includes_CXX.rsp
src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj: ../src/GAMESTATE/titlestate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj"
	cd /d C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\itsatrap.dir\GAMESTATE\titlestate.cpp.obj -c C:\Users\Ugo\Documents\IMAC\itsatrap\src\GAMESTATE\titlestate.cpp

src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.i"
	cd /d C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ugo\Documents\IMAC\itsatrap\src\GAMESTATE\titlestate.cpp > CMakeFiles\itsatrap.dir\GAMESTATE\titlestate.cpp.i

src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.s"
	cd /d C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ugo\Documents\IMAC\itsatrap\src\GAMESTATE\titlestate.cpp -o CMakeFiles\itsatrap.dir\GAMESTATE\titlestate.cpp.s

src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj.requires:

.PHONY : src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj.requires

src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj.provides: src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj.requires
	$(MAKE) -f src\CMakeFiles\itsatrap.dir\build.make src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj.provides.build
.PHONY : src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj.provides

src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj.provides.build: src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj


# Object files for target itsatrap
itsatrap_OBJECTS = \
"CMakeFiles/itsatrap.dir/main.cpp.obj" \
"CMakeFiles/itsatrap.dir/GAME/game.cpp.obj" \
"CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj"

# External object files for target itsatrap
itsatrap_EXTERNAL_OBJECTS =

src/itsatrap.exe: src/CMakeFiles/itsatrap.dir/main.cpp.obj
src/itsatrap.exe: src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj
src/itsatrap.exe: src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj
src/itsatrap.exe: src/CMakeFiles/itsatrap.dir/build.make
src/itsatrap.exe: glimac/libglimac.a
src/itsatrap.exe: src/CMakeFiles/itsatrap.dir/linklibs.rsp
src/itsatrap.exe: src/CMakeFiles/itsatrap.dir/objects1.rsp
src/itsatrap.exe: src/CMakeFiles/itsatrap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable itsatrap.exe"
	cd /d C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\itsatrap.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/itsatrap.dir/build: src/itsatrap.exe

.PHONY : src/CMakeFiles/itsatrap.dir/build

src/CMakeFiles/itsatrap.dir/requires: src/CMakeFiles/itsatrap.dir/main.cpp.obj.requires
src/CMakeFiles/itsatrap.dir/requires: src/CMakeFiles/itsatrap.dir/GAME/game.cpp.obj.requires
src/CMakeFiles/itsatrap.dir/requires: src/CMakeFiles/itsatrap.dir/GAMESTATE/titlestate.cpp.obj.requires

.PHONY : src/CMakeFiles/itsatrap.dir/requires

src/CMakeFiles/itsatrap.dir/clean:
	cd /d C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\src && $(CMAKE_COMMAND) -P CMakeFiles\itsatrap.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/itsatrap.dir/clean

src/CMakeFiles/itsatrap.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ugo\Documents\IMAC\itsatrap C:\Users\Ugo\Documents\IMAC\itsatrap\src C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\src C:\Users\Ugo\Documents\IMAC\itsatrap\cmake-build-debug\src\CMakeFiles\itsatrap.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/itsatrap.dir/depend

