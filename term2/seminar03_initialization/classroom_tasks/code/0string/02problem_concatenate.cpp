/*
    Задача:

        Напищите функцию concatenate, которая будет принимать на вход массив строк и количество строк в массиве.
        Эта функция должна складывать (конкатенировать) все строки и возвращать строку, которая будет равна
        сумме всех строк массива.

        Например в данном примере вызов

            concatenate(animals, 5)

        должен вернуть строку "CatDogMouseAxolotlLion" типа std::string.

*/

#include <iostream>
#include <string>
using std::cout, std::endl;


std::string concatenate(const std::string words[], int numOfWords)
{

}



int main()
{
    std::string animals[5] = {"Cat", "Dog", "Mouse", "Axolotl", "Lion"};

    cout << concatenate(animals, 5) << endl;
}