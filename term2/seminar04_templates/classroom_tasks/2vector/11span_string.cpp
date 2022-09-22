#include <iostream>
#include <vector>
#include <span>


void printSpan(std::span<char> s)
{
    for (auto el : s)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}



int main()
{
    std::string str = "HEllo";

    printSpan(str);
}