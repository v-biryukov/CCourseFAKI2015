cmake_minimum_required(VERSION 2.8.0)
project(player_movement)

# Зададим переменную-строку SFML_DIR = "C:/Workspace/cs_mipt_faki/term2/3rdparty/SFML-2.5.1"
# Вам нужно задать свой путь, то место, где у вас лежит библиотека SFML
#set(SFML_DIR C:/Libs/SFML-2.5.1-source)

# Укажем папку, где нужно искать header-файлы
#include_directories(${SFML_DIR}/include)
# Укажем папку, где нужно искать библиотеки
#link_directories(${SFML_DIR}/lib)

find_package(SFML 2.5 REQUIRED graphics window system)

 
# Создадим исполняемый файл по имени player_movement из исходных файлов
add_executable(player_movement src/main.cpp src/player.cpp src/player_states.cpp)
target_link_libraries(player_movement PRIVATE sfml-graphics)

#include_directories(${SFML_INCLUDE_DIR})
#target_link_libraries(player_movement ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# Подключим статические библиотеки libsfml-graphics.a, libsfml-system.a, libsfml-window.a
#target_link_libraries(player_movement libsfml-graphics.a)
#target_link_libraries(player_movement libsfml-window.a)
#target_link_libraries(player_movement libsfml-system.a)