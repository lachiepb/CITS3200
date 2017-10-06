cmake_minimum_required(VERSION 3.8)
project(CITS3200)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES percolation.c cmake-build-debug stackSite.c stackBond.c percolation.h stackSite.h stackBond.h main.c)
add_executable(CITS3200 ${SOURCE_FILES})