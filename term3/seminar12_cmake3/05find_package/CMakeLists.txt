cmake_minimum_required(VERSION 3.10)
project(FindPackageTest)


set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
find_package(Cat)


find_package(SFML COMPONENTS graphics)


find_package(Elephant)

add_executable(main main.cpp)


message("instal prefix = ${CMAKE_INSTALL_PREFIX}")