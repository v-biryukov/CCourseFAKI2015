cmake_minimum_required(VERSION 3.10)
PROJECT(chat)


add_executable(chat_client chat_client.cpp)
add_executable(chat_server chat_server.cpp)


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREAD ON)
find_package(Boost 1.72.0 COMPONENTS thread system)
if(Boost_FOUND)
  target_link_libraries(chat_client Boost::thread Boost::system)
  target_link_libraries(chat_server Boost::thread Boost::system)
endif(Boost_FOUND)



if(WIN32)
  target_link_libraries(chat_client wsock32 ws2_32)
  target_link_libraries(chat_server wsock32 ws2_32)
endif()
