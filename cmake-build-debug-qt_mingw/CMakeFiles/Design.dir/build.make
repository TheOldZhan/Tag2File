# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.2.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.2.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects\Cpp\Design

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\Cpp\Design\cmake-build-debug-qt_mingw

# Include any dependencies generated for this target.
include CMakeFiles/Design.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Design.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Design.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Design.dir/flags.make

Design_autogen/timestamp: D:/Qt/6.8.1/mingw_64/bin/moc.exe
Design_autogen/timestamp: D:/Qt/6.8.1/mingw_64/bin/uic.exe
Design_autogen/timestamp: CMakeFiles/Design.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\Projects\Cpp\Design\cmake-build-debug-qt_mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target Design"
	"C:\Program Files\JetBrains\CLion 2024.2.3\bin\cmake\win\x64\bin\cmake.exe" -E cmake_autogen D:/Projects/Cpp/Design/cmake-build-debug-qt_mingw/CMakeFiles/Design_autogen.dir/AutogenInfo.json Debug
	"C:\Program Files\JetBrains\CLion 2024.2.3\bin\cmake\win\x64\bin\cmake.exe" -E touch D:/Projects/Cpp/Design/cmake-build-debug-qt_mingw/Design_autogen/timestamp

CMakeFiles/Design.dir/Design_autogen/mocs_compilation.cpp.obj: CMakeFiles/Design.dir/flags.make
CMakeFiles/Design.dir/Design_autogen/mocs_compilation.cpp.obj: CMakeFiles/Design.dir/includes_CXX.rsp
CMakeFiles/Design.dir/Design_autogen/mocs_compilation.cpp.obj: Design_autogen/mocs_compilation.cpp
CMakeFiles/Design.dir/Design_autogen/mocs_compilation.cpp.obj: CMakeFiles/Design.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Projects\Cpp\Design\cmake-build-debug-qt_mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Design.dir/Design_autogen/mocs_compilation.cpp.obj"
	D:\Qt\Tools\mingw1310_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Design.dir/Design_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\Design.dir\Design_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\Design.dir\Design_autogen\mocs_compilation.cpp.obj -c D:\Projects\Cpp\Design\cmake-build-debug-qt_mingw\Design_autogen\mocs_compilation.cpp

CMakeFiles/Design.dir/Design_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Design.dir/Design_autogen/mocs_compilation.cpp.i"
	D:\Qt\Tools\mingw1310_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\Cpp\Design\cmake-build-debug-qt_mingw\Design_autogen\mocs_compilation.cpp > CMakeFiles\Design.dir\Design_autogen\mocs_compilation.cpp.i

CMakeFiles/Design.dir/Design_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Design.dir/Design_autogen/mocs_compilation.cpp.s"
	D:\Qt\Tools\mingw1310_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\Cpp\Design\cmake-build-debug-qt_mingw\Design_autogen\mocs_compilation.cpp -o CMakeFiles\Design.dir\Design_autogen\mocs_compilation.cpp.s

CMakeFiles/Design.dir/fileTools.cpp.obj: CMakeFiles/Design.dir/flags.make
CMakeFiles/Design.dir/fileTools.cpp.obj: CMakeFiles/Design.dir/includes_CXX.rsp
CMakeFiles/Design.dir/fileTools.cpp.obj: D:/Projects/Cpp/Design/fileTools.cpp
CMakeFiles/Design.dir/fileTools.cpp.obj: CMakeFiles/Design.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Projects\Cpp\Design\cmake-build-debug-qt_mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Design.dir/fileTools.cpp.obj"
	D:\Qt\Tools\mingw1310_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Design.dir/fileTools.cpp.obj -MF CMakeFiles\Design.dir\fileTools.cpp.obj.d -o CMakeFiles\Design.dir\fileTools.cpp.obj -c D:\Projects\Cpp\Design\fileTools.cpp

CMakeFiles/Design.dir/fileTools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Design.dir/fileTools.cpp.i"
	D:\Qt\Tools\mingw1310_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\Cpp\Design\fileTools.cpp > CMakeFiles\Design.dir\fileTools.cpp.i

CMakeFiles/Design.dir/fileTools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Design.dir/fileTools.cpp.s"
	D:\Qt\Tools\mingw1310_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\Cpp\Design\fileTools.cpp -o CMakeFiles\Design.dir\fileTools.cpp.s

CMakeFiles/Design.dir/main.cpp.obj: CMakeFiles/Design.dir/flags.make
CMakeFiles/Design.dir/main.cpp.obj: CMakeFiles/Design.dir/includes_CXX.rsp
CMakeFiles/Design.dir/main.cpp.obj: D:/Projects/Cpp/Design/main.cpp
CMakeFiles/Design.dir/main.cpp.obj: CMakeFiles/Design.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Projects\Cpp\Design\cmake-build-debug-qt_mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Design.dir/main.cpp.obj"
	D:\Qt\Tools\mingw1310_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Design.dir/main.cpp.obj -MF CMakeFiles\Design.dir\main.cpp.obj.d -o CMakeFiles\Design.dir\main.cpp.obj -c D:\Projects\Cpp\Design\main.cpp

CMakeFiles/Design.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Design.dir/main.cpp.i"
	D:\Qt\Tools\mingw1310_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\Cpp\Design\main.cpp > CMakeFiles\Design.dir\main.cpp.i

CMakeFiles/Design.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Design.dir/main.cpp.s"
	D:\Qt\Tools\mingw1310_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\Cpp\Design\main.cpp -o CMakeFiles\Design.dir\main.cpp.s

CMakeFiles/Design.dir/mainwindow.cpp.obj: CMakeFiles/Design.dir/flags.make
CMakeFiles/Design.dir/mainwindow.cpp.obj: CMakeFiles/Design.dir/includes_CXX.rsp
CMakeFiles/Design.dir/mainwindow.cpp.obj: D:/Projects/Cpp/Design/mainwindow.cpp
CMakeFiles/Design.dir/mainwindow.cpp.obj: CMakeFiles/Design.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Projects\Cpp\Design\cmake-build-debug-qt_mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Design.dir/mainwindow.cpp.obj"
	D:\Qt\Tools\mingw1310_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Design.dir/mainwindow.cpp.obj -MF CMakeFiles\Design.dir\mainwindow.cpp.obj.d -o CMakeFiles\Design.dir\mainwindow.cpp.obj -c D:\Projects\Cpp\Design\mainwindow.cpp

CMakeFiles/Design.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Design.dir/mainwindow.cpp.i"
	D:\Qt\Tools\mingw1310_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\Cpp\Design\mainwindow.cpp > CMakeFiles\Design.dir\mainwindow.cpp.i

CMakeFiles/Design.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Design.dir/mainwindow.cpp.s"
	D:\Qt\Tools\mingw1310_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\Cpp\Design\mainwindow.cpp -o CMakeFiles\Design.dir\mainwindow.cpp.s

# Object files for target Design
Design_OBJECTS = \
"CMakeFiles/Design.dir/Design_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/Design.dir/fileTools.cpp.obj" \
"CMakeFiles/Design.dir/main.cpp.obj" \
"CMakeFiles/Design.dir/mainwindow.cpp.obj"

# External object files for target Design
Design_EXTERNAL_OBJECTS =

Design.exe: CMakeFiles/Design.dir/Design_autogen/mocs_compilation.cpp.obj
Design.exe: CMakeFiles/Design.dir/fileTools.cpp.obj
Design.exe: CMakeFiles/Design.dir/main.cpp.obj
Design.exe: CMakeFiles/Design.dir/mainwindow.cpp.obj
Design.exe: CMakeFiles/Design.dir/build.make
Design.exe: D:/Qt/6.8.1/mingw_64/lib/libQt6Widgets.a
Design.exe: D:/Qt/6.8.1/mingw_64/lib/libQt6Gui.a
Design.exe: D:/Qt/6.8.1/mingw_64/lib/libQt6Core.a
Design.exe: D:/Qt/6.8.1/mingw_64/lib/libQt6EntryPoint.a
Design.exe: CMakeFiles/Design.dir/linkLibs.rsp
Design.exe: CMakeFiles/Design.dir/objects1.rsp
Design.exe: CMakeFiles/Design.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Projects\Cpp\Design\cmake-build-debug-qt_mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Design.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Design.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Design.dir/build: Design.exe
.PHONY : CMakeFiles/Design.dir/build

CMakeFiles/Design.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Design.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Design.dir/clean

CMakeFiles/Design.dir/depend: Design_autogen/timestamp
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projects\Cpp\Design D:\Projects\Cpp\Design D:\Projects\Cpp\Design\cmake-build-debug-qt_mingw D:\Projects\Cpp\Design\cmake-build-debug-qt_mingw D:\Projects\Cpp\Design\cmake-build-debug-qt_mingw\CMakeFiles\Design.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Design.dir/depend

