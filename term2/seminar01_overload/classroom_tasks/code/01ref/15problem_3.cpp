/*
    Задача:

        Напишите функцию 

            void calculateLetters(char str[], int& numLetters)

        Которая будет принимать на вход строку и считать количество символов букв в этой строке.
        Для определения того, что символ является буквой можно использоваться функцию isalpha библиотеки cctype.

        Например, вызов calculateLetters("ab54AB,gd1:e", x) должен сохранить число 7 в переменную x
*/

#include <iostream>
using std::cout, std::endl;

int main() 
{
    int x;
    calculateLetters("ab54AB,gd1:e", x);
    cout << x << endl;
}

