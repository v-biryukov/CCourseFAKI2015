/*
    Иногда нам хочется передать lvalue выражение в функцию, которая принимает rvalue-ссылку.
    Для этого можно использовать функцию std::move.

    На самом деле, функция std::move просто конвертирует выражение из lvalue в rvalue.
*/

#include <iostream>
#include <string>
using std::cout, std::endl;


void func(std::string& s)
{
    cout << "Pass by lvalue reference" << endl;
}

void func(std::string&& s)
{
    cout << "Pass by rvalue reference" << endl;
}

int main()
{
    std::string s {"Cat"};

    func(s);
    cout << s << endl;

    func(std::move(s));
    cout << s << endl;
}