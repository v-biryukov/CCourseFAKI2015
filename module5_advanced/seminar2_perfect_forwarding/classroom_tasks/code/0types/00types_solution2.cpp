#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "get_type_name.hpp"
using std::cout, std::endl;


void sum(int a, int b) {cout << a + b << endl;};


int main()
{
    void (*p)(int, int) = &sum;
    (*p)(10, 20);


    void (&r)(int, int) = sum;
    r(100, 200);
}