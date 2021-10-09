#include <iostream>
#include "complex.h"
#include <math.h>

using namespace std;

int main () {
    Complex a (5, 2);
    Complex b (3, -3);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "Testing a += b:" << endl;
    a += b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "Testing basic operations:" << endl;
    Complex c = a / b;
    cout << "a + b = " << a + b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << c << endl;
    cout << "(a / b) * b = " << c * b << endl;

    cout << "Testing double + Complex friend functions:" << endl;
    cout << "a = " << a << endl;
    cout << "a + 2 = " << a + 2 << endl;
    cout << "2 + a = " << 2 + a << endl;
    cout << "a * 6 = " << a * 6 << endl;
    cout << "6 * a = " << 6 * a << endl;

    cout << "Testing unary +- operator:" << endl;
    cout << "+a = " << +a << endl;
    cout << "-a = " << -a << endl;

    cout << "Testing unary * operator:" << endl;
    cout << "*a = " << *a << endl;
    return 0;
}