#include <iostream>
using std::cout, std::endl;


/*
    При перемещении о


*/


int main()
{
    int a = 123;
    int b = std::move(a);

    cout << a << " " << b << endl;
}