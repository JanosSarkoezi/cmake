cmake_minimum_required(VERSION 3.16.4)

project(picking)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(doc)
