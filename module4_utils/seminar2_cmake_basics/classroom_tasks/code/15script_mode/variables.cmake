

message(${WIN32})


get_cmake_property(vars VARIABLES)
foreach (v ${vars})
    message("${v}=${${v}}")
endforeach()

message("-------------------------------------------")

include_directories("C:/Users/vova/workspace/libraries/qt/helloworld/build")
get_cmake_property(vars INCLUDE_DIRECTORIES)
foreach (v ${vars})
    message("${v}=${${v}}")
endforeach()
