cmake_minimum_required(VERSION 3.0)
project(image_lib_test)

add_executable(main main.cpp)
target_include_directories(main PUBLIC ./image/include)

add_subdirectory(image)
target_link_libraries(main image)