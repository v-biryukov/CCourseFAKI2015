#include <iostream>
using std::cout, std::endl;
#include "type_name.hpp"

template<typename... Args>
auto sum(Args... args)
{
    return (args + ...);
}


template<typename... Args>
auto print(Args... args)
{
    (cout << ... << args);
}

int main() 
{
    cout << sum(4, 8, 15, 16, 23, 42) << endl;

    print(1, 2, 3);
}