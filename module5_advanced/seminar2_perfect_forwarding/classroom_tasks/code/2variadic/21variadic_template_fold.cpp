#include <iostream>
using std::cout, std::endl;
#include "type_name.hpp"

template<typename... Args>
auto sum(Args... args)
{
    return (args + ...);
}


template<typename... Args>
void print1(Args... args)
{
    (cout << ... << args);
}


template <typename... Args>
void print2(Args... args)
{
    ((std::cout << args << " "), ...) << "\n";
}


template <typename... Args>
void print3(Args&&... args)
{
    ((std::cout << args << " "), ...) << "\n";
}



int main() 
{
    cout << sum(4, 8, 15, 16, 23, 42) << endl;

    print3(1, 2, 3);
}