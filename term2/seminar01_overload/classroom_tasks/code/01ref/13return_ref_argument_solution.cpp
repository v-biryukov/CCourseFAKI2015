#include <iostream>
using std::cout, std::endl;

int* increase(int* p) 
{
    *p += 1;
    return p;
}

int main() 
{
    int a = 10;

    cout << "1) a = " << a << endl;

    increase(&a);
    cout << "2) a = " << a << endl;

    *increase(&a) += 7;
    cout << "3) a = " << a << endl;

    increase(increase(increase(&a)));
    cout << "4) a = " << a << endl;
}