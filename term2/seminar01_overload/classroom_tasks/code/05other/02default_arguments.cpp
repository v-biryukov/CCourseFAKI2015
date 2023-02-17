/*
    В отличии от языка C, в C++ можно задавать значения по умолчанию
    для аргументов функций

    Функцию printSquare можно вызвать с одним, двумя или тремя
    параметрами. Аргументы width и height будут заданы аргументами по умолчанию.
    Если передаваемых аргументов будет меньше трёх.
*/

#include <iostream>
using std::cout, std::endl;

void printSquare(char c, int width = 10, int height = 5) 
{
    for (int i = 0; i < width; i++) 
    {
        for (int j = 0; j < height; j++) 
        {
            cout << c;
        }
        cout << endl;
    }
}

int main() 
{
    printSquare('+', 6, 4);
    printSquare('#', 15);
    printSquare('O');
    

}


/*
    Задание:

    1) Написать функцию:
        void print(char str[], bool isCapitalized = false)
        Которая будет просто печатать строку str, если isCapitalized = false,
        а если isCapitalized = true, то будет печатать всю строку в верхнем регистре
*/