#[[
    Этот код печатает на экран все обычные (не кешированные) 
    переменные и значения этих переменных.

    Многие переменные (и обычные и кешированные) задаются Cmake-ом
    автоматически. Например, переменная CMAKE_SOURCE_DIRECTORY.

    Этот скрипт нужно запускать в скриптовом режиме:

        cmake -P print_all_variables.cmake
]]

set(MY_VARIABLE "Cat")

get_property(out DIRECTORY PROPERTY VARIABLES)
foreach(elem IN LISTS out)
    message("${elem} = ${${elem}}")
endforeach()