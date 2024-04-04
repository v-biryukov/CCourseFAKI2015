#[[
    В данном проекте компилируется либо файл cat.cpp либо файл dog.cpp.
    Если значение переменной CAT истина, то скомпилируется файл cat.cpp.
    Если же значение переменной CAT ложь, то скомпилируется файл dog.cpp.

    Задать значение переменной можно из командной строки, например так:

        cmake -DCAT=on ..

    Выбор файла осуществляется с помощью генераторного выражения:

        $<IF:$<BOOL:${CAT}>,cat.cpp,dog.cpp>

    В этом выражении строка $<BOOL:${CAT}> превращает значение ${CAT} в 0 или 1.
    Строка $<IF:x,cat.cpp,dog.cpp> превратиться в cat.cpp если x равен 1 или
    превратиться в dog.cpp если x равен 0.
]]



cmake_minimum_required(VERSION 3.10)
project(CatOrDog)

message("is cat = ${CAT}")

add_executable(a $<IF:$<BOOL:${CAT}>,cat.cpp,dog.cpp>)
