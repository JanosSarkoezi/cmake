cmake_minimum_required(VERSION 3.16.4)

project(lesson20)

add_executable(lesson20 lesson20.c)

file(COPY Data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(X11 REQUIRED)
find_package(LibM REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(
    lesson20
    ${OPENGL_LIBRARIES}
    ${LIBM_LIBRARIES}
    ${X11_LIBRARIES}
    ${GLUT_LIBRARY}
    )

target_compile_options(
    lesson20
    PRIVATE
    -Wall
    )

