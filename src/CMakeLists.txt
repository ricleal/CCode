cmake_minimum_required (VERSION 2.8)
project (CCode)

set(CMAKE_C_FLAGS   "-O2 -Wall -ggdb" )

add_subdirectory (openmp)

add_executable (ccode main.c)

# For every folder / lib add here:
target_link_libraries (ccode LINK_PUBLIC myopenmp)