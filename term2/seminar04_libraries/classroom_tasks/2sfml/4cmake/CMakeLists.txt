cmake_minimum_required(VERSION 2.8.0)
project(simple_sfml)

# Зададим переменную-строку SFML_DIR = "C:/Users/vova/workspace/latex/cs_mipt_faki/term2/3rdparty/SFML-2.5.1"
# Вам нужно задать свой путь, то место, где у вас лежит библиотека SFML
set(SFML_DIR C:/Users/vova/workspace/latex/cs_mipt_faki/term2/3rdparty/SFML-2.5.1)

# Укажем папку, где нужно искать header-файлы
include_directories(${SFML_DIR}/include)
# Укажем папку, где нужно искать библиотеки
link_directories(${SFML_DIR}/lib)
 
# Создадим исполняемый файл по имени simple_sfml из исходного файла main.cpp
add_executable(simple_sfml main.cpp)

# Подключим статические библиотеки libsfml-graphics.a, libsfml-system.a, libsfml-window.a
target_link_libraries(simple_sfml libsfml-graphics.a)
target_link_libraries(simple_sfml libsfml-window.a)
target_link_libraries(simple_sfml libsfml-system.a)