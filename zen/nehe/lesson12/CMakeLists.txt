cmake_minimum_required(VERSION 3.16.4)

project(lesson12)

add_executable(lesson12 lesson12.c)

file(COPY Data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(LibM REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson12
    OpenGL::GLU
    LIBM::LIBM
    GLUT::GLUT
    )

target_compile_options(
    lesson12
    PRIVATE
    -Wall
    )
