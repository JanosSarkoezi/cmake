cmake_minimum_required(VERSION 3.16.4)

project(lesson10)

add_executable(lesson10 lesson10.c)

file(COPY Data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(LibM REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson10
    OpenGL::GLU
    LIBM::LIBM
    GLUT::GLUT
    )

target_compile_options(
    lesson10
    PRIVATE
    -Wall
    )
