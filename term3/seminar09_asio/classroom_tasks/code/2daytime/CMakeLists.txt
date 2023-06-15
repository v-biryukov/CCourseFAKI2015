cmake_minimum_required(VERSION 3.10)
PROJECT(daytime)


add_executable(daytime_client 01daytime_client.cpp)
add_executable(daytime_server 01daytime_server.cpp)


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREAD ON)
find_package(Boost 1.72.0 COMPONENTS thread system)
if(Boost_FOUND)
  target_link_libraries(daytime_client Boost::thread Boost::system)
  target_link_libraries(daytime_server Boost::thread Boost::system)
endif(Boost_FOUND)



if(WIN32)
  target_link_libraries(daytime_client wsock32 ws2_32)
  target_link_libraries(daytime_server wsock32 ws2_32)
endif()
