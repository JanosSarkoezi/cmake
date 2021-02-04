cmake_minimum_required(VERSION 3.16.4)

project(asm)

add_executable(main
    fixed.c)

find_package(LibM   REQUIRED)

target_link_libraries(main 
    PRIVATE LIBM::LIBM)

target_compile_options(main 
    PRIVATE -Wall)
