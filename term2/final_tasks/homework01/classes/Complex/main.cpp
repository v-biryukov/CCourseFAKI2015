#include <iostream>
#include "complex.h"
#include <math.h>

using namespace std;

int main ()
{
    Complex a (5, 2);
    Complex b (3, -3);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    a += b;
    cout << "a += b:" << endl;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    Complex c = a / b;

    cout << "a + b = " << a + b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << c << endl;

    cout << "(a / b) * b = " << c * b << endl;

    return 0;
}