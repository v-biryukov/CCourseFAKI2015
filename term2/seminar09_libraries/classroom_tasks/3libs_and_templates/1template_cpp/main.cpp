#include <iostream>
#include <string>
#include "tsum.hpp"
using namespace std::string_literals;


int main()
{
    std::cout << sum(10, 20) << std::endl;
    std::cout << sum("Cat"s, "Dog"s) << std::endl;    
}

