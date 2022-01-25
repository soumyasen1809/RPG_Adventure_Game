cmake_minimum_required(VERSION 3.9.1)
project (
    rpg_adventure_game
    VERSION 1.0)

#Bring the headers
include_directories(include)

#Add the sources
set(SOURCES src/main.cpp src/player.cpp src/gameplay.cpp)

#Add executables
add_executable(rpg ${SOURCES})