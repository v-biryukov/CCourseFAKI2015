cmake_minimum_required(VERSION 3.20)
project(HelloProject)

add_executable(hello main.cpp)

set(MY_VARIABLE "Cat")

# Получаем список названий всех переменных в переменную out
# и печатаем эти переменные и их значения на экран
get_property(out DIRECTORY PROPERTY VARIABLES)
foreach(elem IN LISTS out)
    message("${elem} = ${${elem}}")
endforeach()
