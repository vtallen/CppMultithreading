cmake_minimum_required(VERSION 3.25)
set(CMAKE_C_COMPILER "gcc-13")
set(CMAKE_CXX_COMPILER "g++-13")
project(CMakeTemplate)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES
    main.cpp
)

add_executable(main ${SOURCES})

target_link_libraries(main sfml-system sfml-window sfml-graphics)
