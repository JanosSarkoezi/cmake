cmake_minimum_required(VERSION 3.16.4)

project(timer)

add_executable(main
    timer.c)

target_compile_options(main 
    PRIVATE -Wall)
