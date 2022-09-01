#include <iostream>
using std::cout, std::endl;


/*
    Задача:

        Напишите функцию 

            void calculateLetters(char str[], int& numLetters)

        Которая будет принимать на вход строку и считать количество строчных букв в этой строке
        Строчные буквы - это символы от 'a' и до 'z'

        Например, вызов calculateLetters("ab54AB,gd1:e", x) должен сохранить число 5 в переменную x


*/

int main() 
{

    int x;
    calculateLetters("ab54AB,gd1:e", x);
    cout << x << endl;

}

