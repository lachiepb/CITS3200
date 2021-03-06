# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lychee/Documents/CITS3402/CITS3200

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lychee/Documents/CITS3402/CITS3200

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/lychee/Documents/CITS3402/CITS3200/CMakeFiles /home/lychee/Documents/CITS3402/CITS3200/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/lychee/Documents/CITS3402/CITS3200/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named CITS3200

# Build rule for target.
CITS3200: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 CITS3200
.PHONY : CITS3200

# fast build rule for target.
CITS3200/fast:
	$(MAKE) -f CMakeFiles/CITS3200.dir/build.make CMakeFiles/CITS3200.dir/build
.PHONY : CITS3200/fast

main.o: main.c.o

.PHONY : main.o

# target to build an object file
main.c.o:
	$(MAKE) -f CMakeFiles/CITS3200.dir/build.make CMakeFiles/CITS3200.dir/main.c.o
.PHONY : main.c.o

main.i: main.c.i

.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) -f CMakeFiles/CITS3200.dir/build.make CMakeFiles/CITS3200.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s

.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) -f CMakeFiles/CITS3200.dir/build.make CMakeFiles/CITS3200.dir/main.c.s
.PHONY : main.c.s

percolation.o: percolation.c.o

.PHONY : percolation.o

# target to build an object file
percolation.c.o:
	$(MAKE) -f CMakeFiles/CITS3200.dir/build.make CMakeFiles/CITS3200.dir/percolation.c.o
.PHONY : percolation.c.o

percolation.i: percolation.c.i

.PHONY : percolation.i

# target to preprocess a source file
percolation.c.i:
	$(MAKE) -f CMakeFiles/CITS3200.dir/build.make CMakeFiles/CITS3200.dir/percolation.c.i
.PHONY : percolation.c.i

percolation.s: percolation.c.s

.PHONY : percolation.s

# target to generate assembly for a file
percolation.c.s:
	$(MAKE) -f CMakeFiles/CITS3200.dir/build.make CMakeFiles/CITS3200.dir/percolation.c.s
.PHONY : percolation.c.s

stackBond.o: stackBond.c.o

.PHONY : stackBond.o

# target to build an object file
stackBond.c.o:
	$(MAKE) -f CMakeFiles/CITS3200.dir/build.make CMakeFiles/CITS3200.dir/stackBond.c.o
.PHONY : stackBond.c.o

stackBond.i: stackBond.c.i

.PHONY : stackBond.i

# target to preprocess a source file
stackBond.c.i:
	$(MAKE) -f CMakeFiles/CITS3200.dir/build.make CMakeFiles/CITS3200.dir/stackBond.c.i
.PHONY : stackBond.c.i

stackBond.s: stackBond.c.s

.PHONY : stackBond.s

# target to generate assembly for a file
stackBond.c.s:
	$(MAKE) -f CMakeFiles/CITS3200.dir/build.make CMakeFiles/CITS3200.dir/stackBond.c.s
.PHONY : stackBond.c.s

stackSite.o: stackSite.c.o

.PHONY : stackSite.o

# target to build an object file
stackSite.c.o:
	$(MAKE) -f CMakeFiles/CITS3200.dir/build.make CMakeFiles/CITS3200.dir/stackSite.c.o
.PHONY : stackSite.c.o

stackSite.i: stackSite.c.i

.PHONY : stackSite.i

# target to preprocess a source file
stackSite.c.i:
	$(MAKE) -f CMakeFiles/CITS3200.dir/build.make CMakeFiles/CITS3200.dir/stackSite.c.i
.PHONY : stackSite.c.i

stackSite.s: stackSite.c.s

.PHONY : stackSite.s

# target to generate assembly for a file
stackSite.c.s:
	$(MAKE) -f CMakeFiles/CITS3200.dir/build.make CMakeFiles/CITS3200.dir/stackSite.c.s
.PHONY : stackSite.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... CITS3200"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... percolation.o"
	@echo "... percolation.i"
	@echo "... percolation.s"
	@echo "... stackBond.o"
	@echo "... stackBond.i"
	@echo "... stackBond.s"
	@echo "... stackSite.o"
	@echo "... stackSite.i"
	@echo "... stackSite.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

