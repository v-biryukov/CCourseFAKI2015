#include <iostream>
#include <string>
using std::cout, std::endl;

/*
    Задача:

        Напищите функцию changeLetters, которая будет принимать на вход:

            1)  Строку word типа std::string по ссылке
            2)  Символ letter
            3)  Символ newLetter

        Функция changeLetters должна менять строку word. 
        Она должна менять все символы, равные letter, на символы newLetter.

        То есть код в функции main должен напечатать:

            Hello
            Hallo
            Happo

*/

void changeLetters(std::string& word, char letter, char newLetter)
{

}



int main()
{
    std::string a = "Hello";
    cout << a << endl;

    changeLetters(a, 'e', 'a');
    cout << a << endl;

    changeLetters(a, 'l', 'p');
    cout << a << endl;
}