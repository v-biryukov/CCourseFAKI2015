/*
    Бинарное считывание из файла

    Для бинарного считывания нужно открыть файл в режиме std::ios::binary.
    Для считывания используется метод read класса std::ifstream.
    На вход этому методу нужно передать указатель (типа char*) и количество байт для записи.

    В этом примере используется reinterpret_cast для приведения типа int* к типа char*.
*/

#include <iostream>
#include <fstream>
using std::cout, std::endl;

int main()
{
    std::ifstream fin("number.bin", std::ios::binary);

    int a;
    fin.read(reinterpret_cast<char*>(&a), 4);

    cout << a << endl;
}