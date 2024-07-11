cmake_minimum_required(VERSION 3.28)
project(Engine)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.1)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(Engine main.cpp
        Game.cpp
        Game.h
        Ball.cpp
        Ball.h
        Player.cpp
        Player.h)

target_link_libraries(Engine sfml-graphics)