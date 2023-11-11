/*
    Задача:

        Напищите функцию countLetters, которая будет принимать на вход строку типа std::string
        и возвращать количество букв в этой строке.

        Функция countLowerLetters НЕ должна менять строку word. 
*/

#include <iostream>
#include <string>
using std::cout, std::endl;

int main()
{
    std::string a = "Hello123Cat!";
    cout << countLetters(a) << endl;
}