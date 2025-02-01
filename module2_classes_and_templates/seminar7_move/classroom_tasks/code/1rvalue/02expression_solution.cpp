#include <iostream>
#include <string>
using std::cout, std::endl;

int square(int x)
{
    return x * x;
}

int main()
{
    int a = 123;
    float b = 2.5;
    int* p = &a;



}

/*
        1)  a           -   int, lvalue

        2)  2 * a       -   int, rvalue

        3)  a + b       -   float, rvalue

        4)  p           -   int*, lvalue

        5)  *p          -   int, lvalue

        6)  p + a       -   int*, rvalue

        7)  square(a)   -   int, rvalue

        8)  -a          -   int, rvalue

        9)  +a          -   int, rvalue
*/