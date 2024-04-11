cmake_minimum_required(VERSION 3.20)
project(FindPackageTest)

add_executable(main main.cpp)

include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML
)

FetchContent_MakeAvailable(sfml)

target_link_libraries(main PUBLIC 
        sfml-graphics
        sfml-system
        sfml-window)

install(TARGETS sfml-graphics sfml-system sfml-window DESTINATION ${CMAKE_SOURCE_DIR}/bin)