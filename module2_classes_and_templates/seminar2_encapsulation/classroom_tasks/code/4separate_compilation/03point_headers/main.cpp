/*
    Всё что относится к классу Point мы перенесли в отдельный файл point.hpp.
    А также мы разделили объявления и определения методов в файле point.hpp.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include "point.hpp"

using std::cout, std::endl;

int main() 
{
    Point a = {7.2, 3.1};
    cout << a.norm() << endl;
}