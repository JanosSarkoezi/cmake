cmake_minimum_required(VERSION 3.16.4)

project(lesson16)

add_executable(lesson16 lesson16.c)

file(COPY Data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(X11 REQUIRED)
find_package(LibM REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson16
    OpenGL::GLU
    LIBM::LIBM
    GLUT::GLUT
    ${X11_LIBRARIES}
    )

target_compile_options(
    lesson16
    PRIVATE
    -Wall
    )

