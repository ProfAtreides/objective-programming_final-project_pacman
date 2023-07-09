cmake_minimum_required(VERSION 3.22)
project(program)

set(CMAKE_CXX_STANDARD 14)

add_executable(program
        Duch.cpp
        Duch.h
        Gra.cpp
        Gra.h
        Gracz.cpp
        Gracz.h
        "main.cpp")

find_package(SFML 2.5
        COMPONENTS
        system window graphics network audio REQUIRED)

target_include_directories(program
        PRIVATE "${PROJECT_BINARY_DIR}")

target_link_libraries(program sfml-graphics sfml-window sfml-system sfml-audio)

install(TARGETS program DESTINATION bin)