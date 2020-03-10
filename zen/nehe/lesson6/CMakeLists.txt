cmake_minimum_required(VERSION 3.16.4)

project(lesson6)

add_executable(lesson6 lesson6.c)

file(COPY Data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson6
    OpenGL::GLU
    GLUT::GLUT
    )
