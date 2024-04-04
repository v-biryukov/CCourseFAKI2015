cmake_minimum_required(VERSION 3.10)
project(JpgImageProject)

add_executable(main main.cpp)


set(IMAGE_DIR external/image)
add_library(image ${IMAGE_DIR}/image.cpp ${IMAGE_DIR}/image.h)
target_include_directories(image PUBLIC ${IMAGE_DIR})


set(STB_DIR external/stb)
add_library(stb_write ${STB_DIR}/stb_image_write.h)
set_target_properties(stb_write PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(stb_write INTERFACE ${STB_DIR})
target_compile_definitions(stb_write INTERFACE STB_IMAGE_WRITE_IMPLEMENTATION)


target_link_libraries(main PUBLIC stb_write image)