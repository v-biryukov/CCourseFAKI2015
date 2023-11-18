/*
    Конветация строки языка C (то есть в const char*) в строку типа std::string.

    У класса std::string есть конструктор string(const char*) и он вызывается автоматически всегда, когда
    нужно преобразовать строку языка C в строку типа std::string.

    Но его можно сами вызвать конструктор, если хотим явно показать в коде, что мы преобразуем строку языка C в
    строку std::string вот так:

        std::string("Elephant Mouse Tiger")
*/

#include <iostream>
#include <string>
#include <cstring>
using std::cout, std::cin, std::endl;


void func(std::string s)
{
    std::cout << s << std::endl;
}

int main()
{
    char cs[20] = "Cat Dog Mouse";

    std::string s = cs;
    cout << s << endl;

    func("Elephant Mouse Tiger");              
    func(std::string("Elephant Mouse Tiger"));
}