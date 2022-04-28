

set(arr Cat Dog Mouse)

foreach(x IN LISTS arr)
    message(${x})
endforeach()

