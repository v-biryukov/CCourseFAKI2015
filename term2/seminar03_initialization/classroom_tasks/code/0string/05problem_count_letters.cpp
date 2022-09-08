#include <iostream>
#include <string>
using std::cout, std::endl;

/*
    Задача:

        Напищите функцию countLowerLetters, которая будет принимать на вход строку типа std::string
        и возвращать количество строчных букв в этой строке (то есть символов от 'a' до 'z').

        Функция countLowerLetters НЕ должна менять строку word. 
*/


int main()
{
    std::string a = "Hello123Cat!";
    cout << countLowerLetters(a) << endl;
}