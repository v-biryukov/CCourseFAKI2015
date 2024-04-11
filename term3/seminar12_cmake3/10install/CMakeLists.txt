cmake_minimum_required(VERSION 3.10)
project(FindPackageTest)

add_executable(main main.cpp)

message("install prefix: ${CMAKE_INSTALL_PREFIX}")
install(TARGETS main DESTINATION ${CMAKE_SOURCE_DIR}/bin)

include(GNUInstallDirs)
