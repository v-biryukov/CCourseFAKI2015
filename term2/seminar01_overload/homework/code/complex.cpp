#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
    Complex a;
    Complex b;

    cin >> a >> b;

    cout << "a      = "  << a      << endl 
         << "b      = "  << b      << endl 
         << "a + b  = "  << a + b  << endl 
         << "a - b  = "  << a - b  << endl 
         << "a * b  = "  << a * b  << endl 
         << "a / b  = "  << a / b  << endl 
         << "-a     = "  << -a     << endl 
         << "+a     = "  << +a     << endl 
         << "*a     = "  << *a     << endl
         << "a + 5  = "  << a + 5  << endl
         << "5 + a  = "  << 5 + a  << endl
         << "a * 5  = "  << a * 5  << endl
         << "5 * a  = "  << 5 * a  << endl
         << "Exp(a) = "  << exp(a) << endl
         << "Sin(a) = "  << sin(a) << endl
         << "Cos(a) = "  << cos(a) << endl
         << "Exp((a + b) / a) * Cos(a - b) = "  << exp((a + b) / a) * cos(a - b) << endl;
}