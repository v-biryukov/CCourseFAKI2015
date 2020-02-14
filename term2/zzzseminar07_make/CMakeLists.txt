cmake_minimum_required(VERSION 2.6.0)
project(simple)

include_directories(../3rdparty/SFML-2.5.1/include)

#add_definitions(-DCMAKE_SH=CMAKE_SH-NOTFOUND)

SET(COMPILE_FLAGS "-Wall")
SET(LINK_FLAGS  "-lsfml-graphics -lsfml-window -lsfml-system")

add_subdirectory(${CMAKE_SOURCE_DIR}/../3rdparty/SFML-2.5.1)

add_executable(simple simple.cpp)