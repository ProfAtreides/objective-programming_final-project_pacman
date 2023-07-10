cmake_minimum_required(VERSION 3.22)
project(program)

set(CMAKE_CXX_STANDARD 14)

add_executable(program
        source/Ghost.cpp
        source/Ghost.h
        source/Game.cpp
        source/Game.h
        source/Player.cpp
        source/Player.h
        "source/main.cpp" source/Direction.h source/State.h source/Enhancement.cpp source/Enhancement.h source/Point.cpp source/Point.h)

find_package(SFML 2.5
        COMPONENTS
        system window graphics network audio REQUIRED)

target_include_directories(program
        PRIVATE "${PROJECT_BINARY_DIR}")

target_link_libraries(program sfml-graphics sfml-window sfml-system sfml-audio)

install(TARGETS program DESTINATION bin)