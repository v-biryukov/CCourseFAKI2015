/*
    Считывание из файла

    Для считывания из файла используется объект класса std::ifstream.
*/

#include <iostream>
#include <fstream>
using std::cout, std::endl;

int main()
{
    std::ifstream fin("number.txt");

    int a;
    fin >> a;

    cout << a << endl;
}