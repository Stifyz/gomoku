# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = C:\Users\53915\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.3727.114\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\53915\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.3727.114\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\53915\Documents\gomoku

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\53915\Documents\gomoku

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	C:\Users\53915\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.3727.114\bin\cmake\bin\cmake.exe -E echo "No interactive CMake dialog available."
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	C:\Users\53915\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.3727.114\bin\cmake\bin\cmake.exe -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Users\53915\Documents\gomoku\CMakeFiles C:\Users\53915\Documents\gomoku\CMakeFiles\progress.marks
	$(MAKE) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Users\53915\Documents\gomoku\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named pbrain-GroMoCrew

# Build rule for target.
pbrain-GroMoCrew: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 pbrain-GroMoCrew
.PHONY : pbrain-GroMoCrew

# fast build rule for target.
pbrain-GroMoCrew/fast:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/build
.PHONY : pbrain-GroMoCrew/fast

source/AI.obj: source/AI.cpp.obj

.PHONY : source/AI.obj

# target to build an object file
source/AI.cpp.obj:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/AI.cpp.obj
.PHONY : source/AI.cpp.obj

source/AI.i: source/AI.cpp.i

.PHONY : source/AI.i

# target to preprocess a source file
source/AI.cpp.i:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/AI.cpp.i
.PHONY : source/AI.cpp.i

source/AI.s: source/AI.cpp.s

.PHONY : source/AI.s

# target to generate assembly for a file
source/AI.cpp.s:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/AI.cpp.s
.PHONY : source/AI.cpp.s

source/Brain.obj: source/Brain.cpp.obj

.PHONY : source/Brain.obj

# target to build an object file
source/Brain.cpp.obj:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/Brain.cpp.obj
.PHONY : source/Brain.cpp.obj

source/Brain.i: source/Brain.cpp.i

.PHONY : source/Brain.i

# target to preprocess a source file
source/Brain.cpp.i:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/Brain.cpp.i
.PHONY : source/Brain.cpp.i

source/Brain.s: source/Brain.cpp.s

.PHONY : source/Brain.s

# target to generate assembly for a file
source/Brain.cpp.s:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/Brain.cpp.s
.PHONY : source/Brain.cpp.s

source/Game.obj: source/Game.cpp.obj

.PHONY : source/Game.obj

# target to build an object file
source/Game.cpp.obj:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/Game.cpp.obj
.PHONY : source/Game.cpp.obj

source/Game.i: source/Game.cpp.i

.PHONY : source/Game.i

# target to preprocess a source file
source/Game.cpp.i:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/Game.cpp.i
.PHONY : source/Game.cpp.i

source/Game.s: source/Game.cpp.s

.PHONY : source/Game.s

# target to generate assembly for a file
source/Game.cpp.s:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/Game.cpp.s
.PHONY : source/Game.cpp.s

source/Protocol.obj: source/Protocol.cpp.obj

.PHONY : source/Protocol.obj

# target to build an object file
source/Protocol.cpp.obj:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/Protocol.cpp.obj
.PHONY : source/Protocol.cpp.obj

source/Protocol.i: source/Protocol.cpp.i

.PHONY : source/Protocol.i

# target to preprocess a source file
source/Protocol.cpp.i:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/Protocol.cpp.i
.PHONY : source/Protocol.cpp.i

source/Protocol.s: source/Protocol.cpp.s

.PHONY : source/Protocol.s

# target to generate assembly for a file
source/Protocol.cpp.s:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/Protocol.cpp.s
.PHONY : source/Protocol.cpp.s

source/main.obj: source/main.cpp.obj

.PHONY : source/main.obj

# target to build an object file
source/main.cpp.obj:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/main.cpp.obj
.PHONY : source/main.cpp.obj

source/main.i: source/main.cpp.i

.PHONY : source/main.i

# target to preprocess a source file
source/main.cpp.i:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/main.cpp.i
.PHONY : source/main.cpp.i

source/main.s: source/main.cpp.s

.PHONY : source/main.s

# target to generate assembly for a file
source/main.cpp.s:
	$(MAKE) -f CMakeFiles\pbrain-GroMoCrew.dir\build.make CMakeFiles/pbrain-GroMoCrew.dir/source/main.cpp.s
.PHONY : source/main.cpp.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... pbrain-GroMoCrew
	@echo ... edit_cache
	@echo ... rebuild_cache
	@echo ... source/AI.obj
	@echo ... source/AI.i
	@echo ... source/AI.s
	@echo ... source/Brain.obj
	@echo ... source/Brain.i
	@echo ... source/Brain.s
	@echo ... source/Game.obj
	@echo ... source/Game.i
	@echo ... source/Game.s
	@echo ... source/Protocol.obj
	@echo ... source/Protocol.i
	@echo ... source/Protocol.s
	@echo ... source/main.obj
	@echo ... source/main.i
	@echo ... source/main.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system
