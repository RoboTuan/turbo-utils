cmake_minimum_required(VERSION 3.15.3)
project(turbo-utils VERSION 0.0.0)

include(PrintVariables.cmake)
print_variables()
add_subdirectory(DataStructures/)
add_subdirectory(Examples/)
add_subdirectory(Tests/)

