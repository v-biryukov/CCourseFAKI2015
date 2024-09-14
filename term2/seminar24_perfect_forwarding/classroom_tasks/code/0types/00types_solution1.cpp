#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "get_type_name.hpp"
using std::cout, std::endl;

int main()
{
    int a[5] = {10, 20, 30, 40, 50};


    int (*p)[5] = &a;
    (*p)[1] += 1;


    int (&r)[5] = a;
    r[4] += 1;


    for (int i = 0; i < 5; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}