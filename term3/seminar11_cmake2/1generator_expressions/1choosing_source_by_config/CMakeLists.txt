#[[
    В данном проекте компилируется либо файл cat.cpp либо файл dog.cpp.
]]



cmake_minimum_required(VERSION 3.20)
project(CatOrDog)
include(CMakePrintHelpers)

add_executable(a $<IF:$<CONFIG:Debug>,cat.cpp,dog.cpp>)

get_target_property(out a SOURCES)
message("sources = ${out}")

cmake_print_properties(TARGETS a PROPERTIES TYPE)