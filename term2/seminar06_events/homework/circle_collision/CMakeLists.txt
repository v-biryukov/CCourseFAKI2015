cmake_minimum_required(VERSION 2.8.0)
project(collisions)
 
# Создадим исполняемый файл по имени simple_sfml из исходного файла main.cpp
add_executable(1circle_wall src/1circle_wall.cpp)
add_executable(2circle_closest_point src/2circle_closest_point.cpp)
add_executable(3circle_circle src/3circle_circle.cpp)
add_executable(circle_line src/circle_line.cpp)
add_executable(circle_rectangle src/circle_rectangle.cpp)
add_executable(raycasting_circle_line src/raycasting_circle_line.cpp)

# Найдём библиотеку SFML автоматически с компонентами graphics, system и window
find_package(SFML 2.5 COMPONENTS graphics system window)
# Подключим эту библиотеку
target_link_libraries(1circle_wall sfml-graphics sfml-system sfml-window)
target_link_libraries(2circle_closest_point sfml-graphics sfml-system sfml-window)
target_link_libraries(3circle_circle sfml-graphics sfml-system sfml-window)
target_link_libraries(circle_line sfml-graphics sfml-system sfml-window)
target_link_libraries(circle_rectangle sfml-graphics sfml-system sfml-window)
target_link_libraries(raycasting_circle_line sfml-graphics sfml-system sfml-window)