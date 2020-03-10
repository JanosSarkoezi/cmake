project(lib)

add_library(mylib
    STATIC
    myOpenGL.h
    myOpenGL.cpp
    myVertex.h
    myVertex.cpp
    myShader.h
    myShader.cpp)

target_include_directories(mylib
    PRIVATE ../external/glfw/include
    PRIVATE ../external/glad/include
    )

target_link_libraries(mylib 
    PRIVATE glfw
    )

target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
