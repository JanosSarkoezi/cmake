cmake_minimum_required(VERSION 3.16.4)

project(triangle)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(external)
add_subdirectory(lib)
add_subdirectory(src)
