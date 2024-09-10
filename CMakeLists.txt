cmake_minimum_required(VERSION 3.28)
project(RPG)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)

# Fetch SFML
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1  # You can specify the version/tag you want
)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(RPG main.cpp
        Player.cpp
        Headers/Player.hpp
        Logic.cpp
        Headers/Logic.hpp
        BulletManager.cpp
        Headers/BulletManager.hpp
        Headers/stdafx.hpp
        Game.cpp
        Headers/Game.hpp
        Tile.cpp
        Headers/Tile.hpp
        TileMap.cpp
        Headers/TileMap.hpp
)

target_link_libraries(RPG sfml-graphics sfml-system sfml-window)

include_directories(Headers)