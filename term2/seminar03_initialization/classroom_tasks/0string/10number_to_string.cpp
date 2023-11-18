/*
    Конвертация числа в строку. Функция to_string.

    Для конвертации чисел в строку есть удобная функция to_string (библиотека string).
    Работает с числами любых типов.
*/

#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;


int main()
{
    int a = 1234;
    std::string sa = std::to_string(a);

    float b = 3.14159;
    std::string sb = std::to_string(b);

    cout << sa << endl << sb << endl;
}