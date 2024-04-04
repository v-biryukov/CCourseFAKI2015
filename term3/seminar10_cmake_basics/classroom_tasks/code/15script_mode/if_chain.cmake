cmake_minimum_required(VERSION 3.10)

if (ON)
    message(1Cat)
else()
    message(1Dog)
endif()


if (OFF)
    message(2Cat)
else()
    message(2Dog)
endif()


if (hello-NOTFOUND)
    message(3Cat)
else()
    message(3Dog)
endif()


set(bar False)

if (bar)
    message(4Cat)
else()
    message(4Dog)
endif()


if (nosuchvariableexists)
    message(5Cat)
else()
    message(5Dog)
endif()