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
CMAKE_SOURCE_DIR = D:\IMAC2\S3\SI\PROJET\itsatrap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\IMAC2\S3\SI\PROJET\itsatrap\cmake-build-debug

# Include any dependencies generated for this target.
include MAIN/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include MAIN/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include MAIN/CMakeFiles/main.dir/flags.make

MAIN/CMakeFiles/main.dir/main.cpp.obj: MAIN/CMakeFiles/main.dir/flags.make
MAIN/CMakeFiles/main.dir/main.cpp.obj: MAIN/CMakeFiles/main.dir/includes_CXX.rsp
MAIN/CMakeFiles/main.dir/main.cpp.obj: ../MAIN/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\IMAC2\S3\SI\PROJET\itsatrap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object MAIN/CMakeFiles/main.dir/main.cpp.obj"
	cd /d D:\IMAC2\S3\SI\PROJET\itsatrap\cmake-build-debug\MAIN && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main.dir\main.cpp.obj -c D:\IMAC2\S3\SI\PROJET\itsatrap\MAIN\main.cpp

MAIN/CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	cd /d D:\IMAC2\S3\SI\PROJET\itsatrap\cmake-build-debug\MAIN && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\IMAC2\S3\SI\PROJET\itsatrap\MAIN\main.cpp > CMakeFiles\main.dir\main.cpp.i

MAIN/CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	cd /d D:\IMAC2\S3\SI\PROJET\itsatrap\cmake-build-debug\MAIN && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\IMAC2\S3\SI\PROJET\itsatrap\MAIN\main.cpp -o CMakeFiles\main.dir\main.cpp.s

MAIN/CMakeFiles/main.dir/main.cpp.obj.requires:

.PHONY : MAIN/CMakeFiles/main.dir/main.cpp.obj.requires

MAIN/CMakeFiles/main.dir/main.cpp.obj.provides: MAIN/CMakeFiles/main.dir/main.cpp.obj.requires
	$(MAKE) -f MAIN\CMakeFiles\main.dir\build.make MAIN/CMakeFiles/main.dir/main.cpp.obj.provides.build
.PHONY : MAIN/CMakeFiles/main.dir/main.cpp.obj.provides

MAIN/CMakeFiles/main.dir/main.cpp.obj.provides.build: MAIN/CMakeFiles/main.dir/main.cpp.obj


# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

MAIN/main.exe: MAIN/CMakeFiles/main.dir/main.cpp.obj
MAIN/main.exe: MAIN/CMakeFiles/main.dir/build.make
MAIN/main.exe: glimac/libglimac.a
MAIN/main.exe: MAIN/CMakeFiles/main.dir/linklibs.rsp
MAIN/main.exe: MAIN/CMakeFiles/main.dir/objects1.rsp
MAIN/main.exe: MAIN/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\IMAC2\S3\SI\PROJET\itsatrap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main.exe"
	cd /d D:\IMAC2\S3\SI\PROJET\itsatrap\cmake-build-debug\MAIN && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
MAIN/CMakeFiles/main.dir/build: MAIN/main.exe

.PHONY : MAIN/CMakeFiles/main.dir/build

MAIN/CMakeFiles/main.dir/requires: MAIN/CMakeFiles/main.dir/main.cpp.obj.requires

.PHONY : MAIN/CMakeFiles/main.dir/requires

MAIN/CMakeFiles/main.dir/clean:
	cd /d D:\IMAC2\S3\SI\PROJET\itsatrap\cmake-build-debug\MAIN && $(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : MAIN/CMakeFiles/main.dir/clean

MAIN/CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\IMAC2\S3\SI\PROJET\itsatrap D:\IMAC2\S3\SI\PROJET\itsatrap\MAIN D:\IMAC2\S3\SI\PROJET\itsatrap\cmake-build-debug D:\IMAC2\S3\SI\PROJET\itsatrap\cmake-build-debug\MAIN D:\IMAC2\S3\SI\PROJET\itsatrap\cmake-build-debug\MAIN\CMakeFiles\main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : MAIN/CMakeFiles/main.dir/depend

