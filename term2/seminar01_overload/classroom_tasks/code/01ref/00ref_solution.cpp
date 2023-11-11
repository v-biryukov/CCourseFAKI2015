#include <iostream>
using std::cout, std::endl;

int main() 
{
    int a = 10;
    
    int& r = a;
    r += 1;

    cout << a << endl;


    r *= 2;
    cout << a << endl;


    r = 100;
    cout << a << endl;


    float b = 1.5f;
    float& rb = b;

    rb = rb * rb;

    cout << b << endl;
}