cmake_minimum_required(VERSION 3.16.4)

project(lesson9)

add_executable(lesson9 lesson9.c)

file(COPY Data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson9
    OpenGL::GLU
    GLUT::GLUT
    )

target_compile_options(
    lesson9
    PRIVATE
    -Wall
    )

