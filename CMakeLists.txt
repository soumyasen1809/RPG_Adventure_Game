# cmake_minimum_required(VERSION 3.9.1)
# project (
#     rpg_adventure_game
#     VERSION 1.0)

# #Set CMAKE build type and Flags
# set(CMAKE_CXX_FLAGS "-Wall")
# set(CMAKE_BUILD_TYPE Release)

# #Find packages
# find_package(GTest REQUIRED)

# #Bring the headers
# include_directories(include ${GTEST_INCLUDE_DIRS})

# #Add the sources
# set(SOURCES src/main.cpp src/player.cpp src/gameplay.cpp src/trainee.cpp src/mage.cpp src/fighter.cpp test/gtest_project.cpp)

# #Add executables
# add_executable(rpg ${SOURCES})

# #Target link libraries
# target_link_libraries(rpg ${GTEST_LIBRARIES} pthread)

cmake_minimum_required(VERSION 3.10)
project(rpg_adventure_game)

set(CMAKE_CXX_FLAGS "-Wall")

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)
