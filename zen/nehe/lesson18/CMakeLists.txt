cmake_minimum_required(VERSION 3.16.4)

project(lesson18)

add_executable(lesson18 lesson18.c)

file(COPY Data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(LibM REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson18
    OpenGL::GLU
    LIBM::LIBM
    GLUT::GLUT
    )

target_compile_options(
    lesson18
    PRIVATE
    -Wall
    )
