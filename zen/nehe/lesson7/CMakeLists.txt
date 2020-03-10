cmake_minimum_required(VERSION 3.16.4)

project(lesson7)

add_executable(lesson7 lesson7.c)

file(COPY Data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson7
    OpenGL::GLU
    GLUT::GLUT
    )

target_compile_options(
    lesson7
    PRIVATE
    -Wall
    )

