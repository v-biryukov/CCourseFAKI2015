#include <iostream>
#include <cstdlib>
using std::cout, std::endl;


int main()
{
    int a = 10;
    char* p = (char*)&a;


    int* q = (int*)malloc(10 * sizeof(int));
}