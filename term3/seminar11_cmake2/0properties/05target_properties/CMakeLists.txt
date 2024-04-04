cmake_minimum_required(VERSION 3.10)
project(JpgImageProject)

add_executable(main main.cpp)
target_link_options(main PUBLIC -lm)

set(IMAGE_DIR external/image)
add_library(image ${IMAGE_DIR}/image.cpp ${IMAGE_DIR}/image.h)
target_include_directories(image PUBLIC ${IMAGE_DIR})
target_compile_options(image PRIVATE -Wall -Wextra)


set(STB_DIR external/stb)
add_library(stb_write ${STB_DIR}/stb_image_write.h)
set_target_properties(stb_write PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(stb_write INTERFACE ${STB_DIR})
target_compile_definitions(stb_write INTERFACE STB_IMAGE_WRITE_IMPLEMENTATION)


target_link_libraries(main PUBLIC stb_write image)


message("--------- include directories properties ---------------")

get_property(out TARGET image PROPERTY INCLUDE_DIRECTORIES)
message("Include dirs of image: ${out}")

get_property(out TARGET image PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
message("Interface include dirs of image: ${out}")


get_property(out TARGET stb_write PROPERTY INCLUDE_DIRECTORIES)
message("Include dirs of stb_write: ${out}")

get_property(out TARGET stb_write PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
message("Interface include dirs of stb_write: ${out}")


get_property(out TARGET main PROPERTY INCLUDE_DIRECTORIES)
message("Include dirs of main: ${out}")

get_property(out TARGET main PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
message("Interface include dirs of main: ${out}")


message("--------- compile definitions properties ---------------")

get_property(out TARGET stb_write PROPERTY COMPILE_DEFINITIONS)
message("Compile definitions of stb_write: ${out}")

get_property(out TARGET stb_write PROPERTY INTERFACE_COMPILE_DEFINITIONS)
message("Interface compile definitions of stb_write: ${out}")


get_property(out TARGET main PROPERTY COMPILE_DEFINITIONS)
message("Compile definitions of main: ${out}")

get_property(out TARGET main PROPERTY INTERFACE_COMPILE_DEFINITIONS)
message("Interface compile definitions of main: ${out}")


message("--------- compile options properties ---------------")

get_property(out TARGET image PROPERTY COMPILE_OPTIONS)
message("Compile options of image: ${out}")

get_property(out TARGET image PROPERTY INTERFACE_COMPILE_OPTIONS)
message("Interface compile options of image: ${out}")


get_property(out TARGET main PROPERTY COMPILE_OPTIONS)
message("Compile options of main: ${out}")

get_property(out TARGET main PROPERTY INTERFACE_COMPILE_OPTIONS)
message("Interface compile options of main: ${out}")



message("--------- linging properties ---------------")

get_property(out TARGET main PROPERTY LINK_LIBRARIES)
message("Link libraries of main: ${out}")

get_property(out TARGET main PROPERTY LINK_OPTIONS)
message("Link options of main: ${out}")

message("--------- end ---------------")