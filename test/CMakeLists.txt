# cmake_minimum_required(VERSION 3.9.1)
# project (
#     rpg_adventure_game
#     VERSION 1.0)

# ################################
# # GTest
# ################################
# ADD_SUBDIRECTORY (test)
# enable_testing()
# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# ################################
# # Unit Tests
# ################################
# # Add test cpp file
# add_executable( runUnitTests gtest_project.cpp main.cpp)
# # Link test executable against gtest & gtest_main
# target_link_libraries(runUnitTests gtest rpg)
# add_test( runUnitTests runUnitTests )

set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest ${GTEST_LIBRARIES} pthread jsoncpp)
# Remove jsoncpp from above if Jsoncpp not used