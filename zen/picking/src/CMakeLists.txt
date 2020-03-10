cmake_minimum_required(VERSION 3.16.4)

project(pickingMain)

add_executable(main
    picking.cpp)

file(COPY ../shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(OpenGL REQUIRED)
find_package(GLEW   REQUIRED)
find_package(GLUT   REQUIRED)
find_package(LibM   REQUIRED)

target_link_libraries(main 
    PRIVATE OpenGL::OpenGL
    PRIVATE GLEW::GLEW
    PRIVATE GLUT::GLUT
    PRIVATE LIBM::LIBM
    PRIVATE lib)

target_compile_options(main 
    PRIVATE -Wall)
