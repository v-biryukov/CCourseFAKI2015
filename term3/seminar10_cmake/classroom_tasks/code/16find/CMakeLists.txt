cmake_minimum_required(VERSION 3.10)

#project(testing)

find_file(result myfile.cpp HINTS .)
message(${result})