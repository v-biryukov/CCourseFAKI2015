/*
    to_string

    Для конвертации чисел в строку есть удобная функция to_string (библиотека string)

    Для конвертации из строки в число можно использовать функции 
    stoi (для int), stoll (для long long), stof(для float), stod(для double)

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


    int c = std::stoi(sa);
    cout << c << endl;

    float d = std::stof(sb);
    cout << d << endl;
}