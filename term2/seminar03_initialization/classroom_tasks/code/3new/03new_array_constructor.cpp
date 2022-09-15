/*
    Операторы new[] и delete[]

    Можно сразу инициализировать все объекты в Куче через фигурные скобочки.
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
    void setName(const std::string& name) {mname = name;};
};


int main()
{
    Cat* p = new Cat[3] {{"Alice", 10}, {"Bob", 20}, {"Chloe", 30}};
}




/*
    Задачи:

        1)  Удалите массив объектов с помощью оператора delete[]

        2)  В каком порядке вызываются деструкторы объектов?

        3)  Создайте в Куче массив из 5 элементов типа int и инициализируйте его значениями 10 20 30 40 50
*/