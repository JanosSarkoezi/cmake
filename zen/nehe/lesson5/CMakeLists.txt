cmake_minimum_required(VERSION 3.16.4)

project(lesson1)

add_executable(lesson5 lesson5.c)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson5
    OpenGL::GLU
    GLUT::GLUT
    )

target_compile_options(
    lesson5
    PRIVATE
    -Wall
    )

