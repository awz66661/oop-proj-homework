# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = D:\Code\vscode\MyHomeWork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code\vscode\MyHomeWork\build

# Include any dependencies generated for this target.
include CMakeFiles/findKthStr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/findKthStr.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/findKthStr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/findKthStr.dir/flags.make

CMakeFiles/findKthStr.dir/findKthStr.cpp.obj: CMakeFiles/findKthStr.dir/flags.make
CMakeFiles/findKthStr.dir/findKthStr.cpp.obj: CMakeFiles/findKthStr.dir/includes_CXX.rsp
CMakeFiles/findKthStr.dir/findKthStr.cpp.obj: ../findKthStr.cpp
CMakeFiles/findKthStr.dir/findKthStr.cpp.obj: CMakeFiles/findKthStr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Code\vscode\MyHomeWork\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/findKthStr.dir/findKthStr.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/findKthStr.dir/findKthStr.cpp.obj -MF CMakeFiles\findKthStr.dir\findKthStr.cpp.obj.d -o CMakeFiles\findKthStr.dir\findKthStr.cpp.obj -c D:\Code\vscode\MyHomeWork\findKthStr.cpp

CMakeFiles/findKthStr.dir/findKthStr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/findKthStr.dir/findKthStr.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\vscode\MyHomeWork\findKthStr.cpp > CMakeFiles\findKthStr.dir\findKthStr.cpp.i

CMakeFiles/findKthStr.dir/findKthStr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/findKthStr.dir/findKthStr.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\vscode\MyHomeWork\findKthStr.cpp -o CMakeFiles\findKthStr.dir\findKthStr.cpp.s

# Object files for target findKthStr
findKthStr_OBJECTS = \
"CMakeFiles/findKthStr.dir/findKthStr.cpp.obj"

# External object files for target findKthStr
findKthStr_EXTERNAL_OBJECTS =

findKthStr.exe: CMakeFiles/findKthStr.dir/findKthStr.cpp.obj
findKthStr.exe: CMakeFiles/findKthStr.dir/build.make
findKthStr.exe: CMakeFiles/findKthStr.dir/linklibs.rsp
findKthStr.exe: CMakeFiles/findKthStr.dir/objects1.rsp
findKthStr.exe: CMakeFiles/findKthStr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Code\vscode\MyHomeWork\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable findKthStr.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\findKthStr.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/findKthStr.dir/build: findKthStr.exe
.PHONY : CMakeFiles/findKthStr.dir/build

CMakeFiles/findKthStr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\findKthStr.dir\cmake_clean.cmake
.PHONY : CMakeFiles/findKthStr.dir/clean

CMakeFiles/findKthStr.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code\vscode\MyHomeWork D:\Code\vscode\MyHomeWork D:\Code\vscode\MyHomeWork\build D:\Code\vscode\MyHomeWork\build D:\Code\vscode\MyHomeWork\build\CMakeFiles\findKthStr.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/findKthStr.dir/depend
