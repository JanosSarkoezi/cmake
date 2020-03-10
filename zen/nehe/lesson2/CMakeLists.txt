cmake_minimum_required(VERSION 3.16.4)

project(lesson2)

add_executable(lesson2 lesson2.c)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson2
    OpenGL::GLU
    GLUT::GLUT
    )

target_compile_options(
    lesson2
    PRIVATE
    -Wall
    )

