#include <iostream>

int getMax(int a, int b) 
{
    return a > b ? a : b;
}


int main() 
{
    float x = 5.5;
    float y = 1.7; 
    std::cout << getMax(x, y) << std::endl;
}