/*
    Количество знаков после запятой

    std::setprecision используется для указания количества печатаемых знаков после запятой
*/


#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout, std::endl;

int main()
{
    double x = std::sqrt(2);

    cout << x << endl;

    cout << std::setprecision(10);
    cout << x << endl;

    cout << std::setprecision(20);
    cout << x << endl;
}