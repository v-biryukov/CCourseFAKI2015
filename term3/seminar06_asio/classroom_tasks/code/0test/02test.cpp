//
// timer.cpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2016 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>
#include <thread>
using std::cout, std::endl;

void print(const std::string& message)
{
    std::cout << message << std::endl;
}


int main()
{
  boost::asio::io_context io;


  std::vector vs {"Cat", "Mouse", "Elephant", "Dog", "Tiger", "Lion", "Axolotl"};

  for (const auto& s : vs)
    boost::asio::post(io, std::bind(print, s));



  std::thread t1([&io]() { io.run(); });
  std::thread t2([&io]() { io.run(); });
  std::thread t3([&io]() { io.run(); });


  t1.join();
  t2.join();
  t3.join();
  
  return 0;
}