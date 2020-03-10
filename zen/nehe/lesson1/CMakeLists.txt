cmake_minimum_required(VERSION 3.16.4)

project(lesson1)

add_executable(lesson1 lesson1.c)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson1
    PRIVATE
      OpenGL::GLU
      GLUT::GLUT
    )

target_compile_options(
    lesson1
    PRIVATE
    -Wall
    )
