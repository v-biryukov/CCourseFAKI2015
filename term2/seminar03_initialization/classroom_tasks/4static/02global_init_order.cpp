/*
    Инициализация глобальных переменных

    Ещё один интересный момент - когда происходит инициализация глобальных переменных?
    Если глобальная переменная - это класс, то когда вызывается её конструктор, а когда деструктор?

    На самом деле, все глобальные и статические объекты должны создаваться в самом начале, ещё до
    функции main, а разрушаться в самом конце - после функции main.


    Задача 1:

        Что напечатаеть данная программа?

    Задача 2:

        Напишите программу Hello World!, но при этом функция main должна быть пустой
        (в функции main не должно быть ни одной строчки).
*/

#include <iostream>
#include <string>
using std::cout, std::endl;

class Verbose
{
private:
    std::string mName {};
public:
    Verbose()   {std::cout << "Default Constructor (" << mName << ")" << std::endl;}
    ~Verbose()  {std::cout << "Destructor (" << mName << ")" << std::endl;}
    Verbose(const std::string& name) : mName(name)    {std::cout << "Constructor from std::string (" << mName << ")" << std::endl;}
    Verbose(const Verbose& v)        : mName(v.mName) {std::cout << "Copy Constructor (" << mName << ")" << std::endl;}
    std::string getName() const {return mName;}
};

Verbose a("Alice");

int main()
{
    Verbose b("Bob");
    Verbose c("Casper");
}
