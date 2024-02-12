cmake_minimum_required(VERSION 3.17)
project(PacManDuel)

set(CMAKE_CXX_STANDARD 20)

add_executable(PacManDuel
        main.cpp
        source/Engine/Gra.hpp source/Engine/Gra.cpp
        source/Monster/Duch.hpp source/Monster/Duch.cpp
        source/Player/Gracz.hpp source/Player/Gracz.cpp)

include_directories(headers external/SFML/include)

set(SFML_ROOT external/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PacManDuel ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()