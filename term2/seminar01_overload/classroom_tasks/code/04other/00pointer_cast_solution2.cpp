#include <iostream>
#include <cstdlib>
using std::cout, std::endl;


/*
    В языке C++ желательно использовать более безопасное приведение типов static_cast
*/

int main()
{
    int a = 10;
    char* p = static_cast<char*>(&a);


    int* q = static_cast<int*>(malloc(10 * sizeof(int)));
}