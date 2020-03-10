cmake_minimum_required(VERSION 3.16.4)

project(lesson8)

add_executable(lesson8 lesson8.c)

file(COPY Data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson8
    OpenGL::GLU
    GLUT::GLUT
    )

target_compile_options(
    lesson8
    PRIVATE
    -Wall
    )

