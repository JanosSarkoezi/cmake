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
