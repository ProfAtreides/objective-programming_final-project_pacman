cmake_minimum_required(VERSION 3.22)
project(everything)
project(currentTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(everything
        source/Ghost.cpp
        source/Ghost.h
        source/Game.cpp
        source/Game.h
        source/Player.cpp
        source/Player.h
        "source/main.cpp" source/Direction.h source/State.h source/Enhancement.cpp source/Enhancement.h source/Point.cpp source/Point.h source/WindowHandler.cpp source/WindowHandler.h source/Map.cpp source/Map.h)

add_executable(currentTest source/WindowHandler.h source/WindowHandler.cpp source/main.cpp)

find_package(SFML 2.5
        COMPONENTS
        system window graphics network audio REQUIRED)

target_include_directories(everything
        PRIVATE "${PROJECT_BINARY_DIR}")
target_link_libraries(everything sfml-graphics sfml-window sfml-system sfml-audio)

target_include_directories(currentTest PRIVATE "${PROJECT_BINARY_DIR}")
target_link_libraries(currentTest sfml-graphics sfml-window sfml-system sfml-audio)

install(TARGETS everything DESTINATION bin)