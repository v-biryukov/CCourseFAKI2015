/*
    Оператор new

    С помощью оператора new можно сразу инициализировать объект нужным образом.
    Для этого нужно передать аргументы для инициализации в круглых или фигурных скобках.
*/

#include <iostream>
#include <cstdlib>
#include <string>
using std::cout, std::endl, std::string;

class Cat
{
private:
    string mname {};
    int mage     {};

public:
    Cat()   {cout << "Cat Default Constructor (" << mname << ")" << endl;}
    ~Cat()  {cout << "Cat Destructor ("          << mname << ")" << endl;}
    Cat(const Cat& c)                : mname(c.mname), mage(c.mage) {cout << "Cat Copy Constructor (" << mname << ")" << endl;}
    Cat(const string& name, int age) : mname(name),    mage(age)    {cout << "Cat Constructor ("      << mname << ")" << endl;}
};


int main()
{
    Cat* pa = new Cat("Alice",  10);
    Cat* pb = new Cat{"Bob",    20};


    delete pa;
    delete pb;
}




/*
    Задачи:

        1)  Что напечатает данная программа? В каком порядке вызовутся деструкторы?

        2)  Создайте объект типа Cat в Куче с помощью конструктора копирования из объекта a.

        3)  Создайте объект типа int в Куче и инициализируйте его числом 123.
*/