#[[
    Этот код печатает на экран все доступные команды Cmake.

    Этот скрипт нужно запускать в скриптовом режиме:

        cmake -P print_all_commands.cmake
]]

get_property(out GLOBAL PROPERTY COMMANDS)

foreach(elem IN LISTS out)
    message(${elem})
endforeach()