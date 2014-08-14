cmake_minimum_required(VERSION 2.8.7)
project(RevolutionBMS)

enable_language(C)
enable_language(CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

set(CMAKE_CXX_FLAGS "-std=c++11 -Bstatic -Wall -Wno-unknown-pragmas")

option(test "Build all tests." ON)

add_subdirectory(src)
add_subdirectory(tests)

