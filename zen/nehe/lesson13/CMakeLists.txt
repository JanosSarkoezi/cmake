cmake_minimum_required(VERSION 3.16.4)

project(lesson13)

add_executable(lesson13 lesson13.c)

find_package(X11 REQUIRED)
find_package(LibM REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson13
    OpenGL::GLU
    LIBM::LIBM
    GLUT::GLUT
    X11::X11
    )

target_compile_options(
    lesson13
    PRIVATE
    -Wall
    )
