cmake_minimum_required(VERSION 3.16.4)

project(generator)

set(PROJECT       project)
set(LIB_CLASS     Generator)
set(LIB_CLASS_DEF GENERATOR)
set(LIB_NAME      genlib)
set(LIB_NAMESPACE gen)
set(CCSD          \${CMAKE_CURRENT_SOURCE_DIR})

configure_file(resources/CMakeListsRoot.txt.in ${PROJECT}/CMakeLists.txt)
configure_file(resources/CMakeListsSrc.txt.in  ${PROJECT}/src/CMakeLists.txt)
configure_file(resources/main.cpp.in           ${PROJECT}/src/main.cpp)
configure_file(resources/CMakeListsLib.txt.in  ${PROJECT}/lib/CMakeLists.txt)
configure_file(resources/lib.cpp.in            ${PROJECT}/lib/${LIB_CLASS}.cpp)
configure_file(resources/lib.h.in              ${PROJECT}/lib/${LIB_CLASS}.h)
configure_file(resources/CMakeListsTest.txt.in ${PROJECT}/test/CMakeLists.txt)
configure_file(resources/test.cpp.in           ${PROJECT}/test/test${LIB_CLASS}.cpp)
