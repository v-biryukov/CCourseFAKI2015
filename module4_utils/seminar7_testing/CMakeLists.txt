cmake_minimum_required(VERSION 3.10)
project(LinkedListTesting)
include(CTest)


add_library(linkedList STATIC linkedList.cpp linkedList.hpp)
target_include_directories(linkedList PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(main main.cpp)
target_link_libraries(main PUBLIC linkedList)


find_package(GTest REQUIRED)
if(NOT GTest_FOUND)
    message("GTest not found!")
endif()


add_executable(myTest myTest.cpp)
target_link_libraries(myTest PUBLIC linkedList)
target_link_libraries(myTest PUBLIC GTest::gtest GTest::gtest_main)


enable_testing()
add_test(NAME t1 COMMAND myTest)