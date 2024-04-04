cmake_minimum_required(VERSION 3.20)
project(CreatingImageProject)


add_library(image image.cpp image.h)
add_executable(main main.cpp)
target_link_libraries(main PUBLIC image)

# Получаем список названий всех таргетов в переменную out
# и печатаем эти названия таргетов на экран
get_property(out DIRECTORY PROPERTY BUILDSYSTEM_TARGETS)
message("Printing all targets:")
foreach(elem IN LISTS out)
    message("${elem}")
endforeach()
