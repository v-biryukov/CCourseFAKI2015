/*
    Считывание с экрана с помошью std::cin

    Для считывания с экрана в языке C++ используется std::cin.
    В отличии от языка C, тут не нужно указывать никаких спецификаторов.
    Компилятор сам догадается какую перегрузку функции operator>> нужно выбрать.
*/

#include <iostream>
using std::cout, std::cin, std::endl;

int main()
{
    int a;
    cin >> a;
    cout << a << endl;

    float b;
    cin >> b;
    cout << b << endl;
}