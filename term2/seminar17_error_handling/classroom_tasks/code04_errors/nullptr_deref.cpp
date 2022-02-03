#include <iostream>


int main()
{
    int* p = nullptr;

    // Undefined behavior
    std::cout << *p;
}