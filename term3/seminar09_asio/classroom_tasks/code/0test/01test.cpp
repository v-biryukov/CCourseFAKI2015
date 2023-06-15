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
using std::cout, std::endl;

void print(const std::string& message)
{
    std::cout << message << std::endl;
}


int main()
{
  boost::asio::io_context io;


  boost::asio::post(io, std::bind(print, std::string("Cat")));
  boost::asio::post(io, std::bind(print, std::string("Mouse")));
  boost::asio::post(io, std::bind(print, std::string("Elephant")));


  cout << "Before run" << endl;
  io.run();
  cout << "After run" << endl;
  
  return 0;
}