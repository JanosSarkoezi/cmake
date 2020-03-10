cmake_minimum_required(VERSION 3.16.4)

project(lesson19)

add_executable(lesson19 lesson19.cc)

file(COPY Data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(X11 REQUIRED)
find_package(SDL2 REQUIRED)
find_package(LibM REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson19
    OpenGL::GLU
    LIBM::LIBM
    GLUT::GLUT
    ${SDL2_LIBRARIES}
    ${X11_LIBRARIES}
    )

target_compile_options(
    lesson19
    PRIVATE
    -Wall
    )

