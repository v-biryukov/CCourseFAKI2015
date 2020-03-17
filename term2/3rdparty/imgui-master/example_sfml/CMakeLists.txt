project(imgui_sfml_example
  LANGUAGES CXX
)

include_directories(C:/Users/vova/workspace/latex/cs_mipt_faki/term2/3rdparty/imgui-master)
include_directories(/c/Users/vova/workspace/latex/cs_mipt_faki/term2/3rdparty/SFML-2.5.1)
add_executable(imgui_sfml_example
  main.cpp
  ${IMGUI_DEMO_SOURCES}
)

target_link_libraries(imgui_sfml_example PRIVATE ImGui-SFML::ImGui-SFML)
