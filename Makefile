# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nnovitzk/work/011.ALICE/000.Focal/007.FoCalGeant4/source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nnovitzk/work/011.ALICE/000.Focal/007.FoCalGeant4

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.18.1/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.18.1/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.18.1/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.18.1/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.18.1/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.18.1/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.18.1/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.18.1/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/nnovitzk/work/011.ALICE/000.Focal/007.FoCalGeant4/CMakeFiles /Users/nnovitzk/work/011.ALICE/000.Focal/007.FoCalGeant4//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/nnovitzk/work/011.ALICE/000.Focal/007.FoCalGeant4/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named FoCal_Main

# Build rule for target.
FoCal_Main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 FoCal_Main
.PHONY : FoCal_Main

# fast build rule for target.
FoCal_Main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/build
.PHONY : FoCal_Main/fast

#=============================================================================
# Target rules for targets named FoCal_MainClassesDict

# Build rule for target.
FoCal_MainClassesDict: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 FoCal_MainClassesDict
.PHONY : FoCal_MainClassesDict

# fast build rule for target.
FoCal_MainClassesDict/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/build
.PHONY : FoCal_MainClassesDict/fast

FoCal_Main.o: FoCal_Main.cc.o

.PHONY : FoCal_Main.o

# target to build an object file
FoCal_Main.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/FoCal_Main.cc.o
.PHONY : FoCal_Main.cc.o

FoCal_Main.i: FoCal_Main.cc.i

.PHONY : FoCal_Main.i

# target to preprocess a source file
FoCal_Main.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/FoCal_Main.cc.i
.PHONY : FoCal_Main.cc.i

FoCal_Main.s: FoCal_Main.cc.s

.PHONY : FoCal_Main.s

# target to generate assembly for a file
FoCal_Main.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/FoCal_Main.cc.s
.PHONY : FoCal_Main.cc.s

src/EventAction.o: src/EventAction.cc.o

.PHONY : src/EventAction.o

# target to build an object file
src/EventAction.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/EventAction.cc.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/EventAction.cc.o
.PHONY : src/EventAction.cc.o

src/EventAction.i: src/EventAction.cc.i

.PHONY : src/EventAction.i

# target to preprocess a source file
src/EventAction.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/EventAction.cc.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/EventAction.cc.i
.PHONY : src/EventAction.cc.i

src/EventAction.s: src/EventAction.cc.s

.PHONY : src/EventAction.s

# target to generate assembly for a file
src/EventAction.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/EventAction.cc.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/EventAction.cc.s
.PHONY : src/EventAction.cc.s

src/Geometry.o: src/Geometry.cc.o

.PHONY : src/Geometry.o

# target to build an object file
src/Geometry.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/Geometry.cc.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/Geometry.cc.o
.PHONY : src/Geometry.cc.o

src/Geometry.i: src/Geometry.cc.i

.PHONY : src/Geometry.i

# target to preprocess a source file
src/Geometry.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/Geometry.cc.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/Geometry.cc.i
.PHONY : src/Geometry.cc.i

src/Geometry.s: src/Geometry.cc.s

.PHONY : src/Geometry.s

# target to generate assembly for a file
src/Geometry.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/Geometry.cc.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/Geometry.cc.s
.PHONY : src/Geometry.cc.s

src/PrimaryGenerator.o: src/PrimaryGenerator.cc.o

.PHONY : src/PrimaryGenerator.o

# target to build an object file
src/PrimaryGenerator.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/PrimaryGenerator.cc.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/PrimaryGenerator.cc.o
.PHONY : src/PrimaryGenerator.cc.o

src/PrimaryGenerator.i: src/PrimaryGenerator.cc.i

.PHONY : src/PrimaryGenerator.i

# target to preprocess a source file
src/PrimaryGenerator.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/PrimaryGenerator.cc.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/PrimaryGenerator.cc.i
.PHONY : src/PrimaryGenerator.cc.i

src/PrimaryGenerator.s: src/PrimaryGenerator.cc.s

.PHONY : src/PrimaryGenerator.s

# target to generate assembly for a file
src/PrimaryGenerator.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/PrimaryGenerator.cc.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/PrimaryGenerator.cc.s
.PHONY : src/PrimaryGenerator.cc.s

src/RootIO.o: src/RootIO.cc.o

.PHONY : src/RootIO.o

# target to build an object file
src/RootIO.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/RootIO.cc.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/RootIO.cc.o
.PHONY : src/RootIO.cc.o

src/RootIO.i: src/RootIO.cc.i

.PHONY : src/RootIO.i

# target to preprocess a source file
src/RootIO.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/RootIO.cc.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/RootIO.cc.i
.PHONY : src/RootIO.cc.i

src/RootIO.s: src/RootIO.cc.s

.PHONY : src/RootIO.s

# target to generate assembly for a file
src/RootIO.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/RootIO.cc.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/RootIO.cc.s
.PHONY : src/RootIO.cc.s

src/RunAction.o: src/RunAction.cc.o

.PHONY : src/RunAction.o

# target to build an object file
src/RunAction.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/RunAction.cc.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/RunAction.cc.o
.PHONY : src/RunAction.cc.o

src/RunAction.i: src/RunAction.cc.i

.PHONY : src/RunAction.i

# target to preprocess a source file
src/RunAction.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/RunAction.cc.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/RunAction.cc.i
.PHONY : src/RunAction.cc.i

src/RunAction.s: src/RunAction.cc.s

.PHONY : src/RunAction.s

# target to generate assembly for a file
src/RunAction.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/RunAction.cc.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/RunAction.cc.s
.PHONY : src/RunAction.cc.s

src/SteppingAction.o: src/SteppingAction.cc.o

.PHONY : src/SteppingAction.o

# target to build an object file
src/SteppingAction.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/SteppingAction.cc.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/SteppingAction.cc.o
.PHONY : src/SteppingAction.cc.o

src/SteppingAction.i: src/SteppingAction.cc.i

.PHONY : src/SteppingAction.i

# target to preprocess a source file
src/SteppingAction.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/SteppingAction.cc.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/SteppingAction.cc.i
.PHONY : src/SteppingAction.cc.i

src/SteppingAction.s: src/SteppingAction.cc.s

.PHONY : src/SteppingAction.s

# target to generate assembly for a file
src/SteppingAction.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/SteppingAction.cc.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/SteppingAction.cc.s
.PHONY : src/SteppingAction.cc.s

src/UserActionInitialization.o: src/UserActionInitialization.cc.o

.PHONY : src/UserActionInitialization.o

# target to build an object file
src/UserActionInitialization.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/UserActionInitialization.cc.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/UserActionInitialization.cc.o
.PHONY : src/UserActionInitialization.cc.o

src/UserActionInitialization.i: src/UserActionInitialization.cc.i

.PHONY : src/UserActionInitialization.i

# target to preprocess a source file
src/UserActionInitialization.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/UserActionInitialization.cc.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/UserActionInitialization.cc.i
.PHONY : src/UserActionInitialization.cc.i

src/UserActionInitialization.s: src/UserActionInitialization.cc.s

.PHONY : src/UserActionInitialization.s

# target to generate assembly for a file
src/UserActionInitialization.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_Main.dir/build.make CMakeFiles/FoCal_Main.dir/src/UserActionInitialization.cc.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/FoCal_MainClassesDict.dir/build.make CMakeFiles/FoCal_MainClassesDict.dir/src/UserActionInitialization.cc.s
.PHONY : src/UserActionInitialization.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... FoCal_Main"
	@echo "... FoCal_MainClassesDict"
	@echo "... FoCal_Main.o"
	@echo "... FoCal_Main.i"
	@echo "... FoCal_Main.s"
	@echo "... src/EventAction.o"
	@echo "... src/EventAction.i"
	@echo "... src/EventAction.s"
	@echo "... src/Geometry.o"
	@echo "... src/Geometry.i"
	@echo "... src/Geometry.s"
	@echo "... src/PrimaryGenerator.o"
	@echo "... src/PrimaryGenerator.i"
	@echo "... src/PrimaryGenerator.s"
	@echo "... src/RootIO.o"
	@echo "... src/RootIO.i"
	@echo "... src/RootIO.s"
	@echo "... src/RunAction.o"
	@echo "... src/RunAction.i"
	@echo "... src/RunAction.s"
	@echo "... src/SteppingAction.o"
	@echo "... src/SteppingAction.i"
	@echo "... src/SteppingAction.s"
	@echo "... src/UserActionInitialization.o"
	@echo "... src/UserActionInitialization.i"
	@echo "... src/UserActionInitialization.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

