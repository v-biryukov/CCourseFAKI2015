cmake_minimum_required(VERSION 2.8.0)
project(simple_sfml)

set(CMAKE_MODULE_PATH C:/Users/vova/workspace/latex/cs_mipt_faki/term2/3rdparty/imgui-master/cmake)
set(IMGUI_DIR C:/Users/vova/workspace/latex/cs_mipt_faki/term2/3rdparty/imgui-master)
# Создадим исполняемый файл по имени simple_sfml из исходного файла main.cpp
add_executable(simple_sfml main.cpp)

# Найдём библиотеку SFML автоматически с компонентами graphics, system и window
find_package(SFML 2.5 COMPONENTS graphics system window)

find_package(ImGui)


# Подключим эту библиотеку
target_link_libraries(simple_sfml sfml-graphics sfml-system sfml-window)