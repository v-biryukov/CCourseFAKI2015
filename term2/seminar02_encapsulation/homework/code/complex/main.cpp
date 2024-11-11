#include <iostream>
#include "complex.hpp"

using std::cout, std::cin, std::endl;

// Тут мы тестируем нашу реализацию комплексных чисел

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

    a += b;
    cout << "a += b; a = " << a << endl;

    // Оператор = мы не перегружали, но это всё равно работает
    b = a;
    cout << "b = a; b = " << b << endl;
}