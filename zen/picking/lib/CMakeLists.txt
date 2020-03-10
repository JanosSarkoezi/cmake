project(library)

add_library(lib
    STATIC
    vsLogLib.cpp
    vsLogLib.h
    vsMathLib.cpp
    vsMathLib.h
    vsResourceLib.cpp
    vsResourceLib.h
    vsResSurfRevLib.cpp
    vsResSurfRevLib.h
    vsShaderLib.cpp
    vsShaderLib.h)

find_package(LibM REQUIRED)

target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(lib
    PRIVATE LIBM::LIBM)
