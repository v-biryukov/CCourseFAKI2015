cmake_minimum_required(VERSION 3.10)
PROJECT(timer)


add_executable(timer 02timer.cpp)


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREAD ON)
find_package(Boost 1.72.0 COMPONENTS thread system)
if(Boost_FOUND)
  target_link_libraries(timer Boost::thread Boost::system)
endif(Boost_FOUND)



if(WIN32)
  target_link_libraries(timer wsock32 ws2_32)
endif()
