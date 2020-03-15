cmake_minimum_required(VERSION 3.16.4)

add_executable(main
    main.cpp)

file(COPY ../resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(main 
    PRIVATE glfw
    PRIVATE glad
    PRIVATE glm
    PRIVATE mylib
    )

target_compile_options(main 
    PRIVATE -Wall
    )


add_executable(transformation
    shader_m.h
    transformation.cpp)

target_link_libraries(transformation
    PRIVATE glfw
    PRIVATE glad
    PRIVATE glm
    PRIVATE stb
    )
