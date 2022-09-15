/*
    Операторы new[] и delete[]

    С помощью оператора new[] можно сразу создать массив из объектов в Куче.
    Чтобы создать сразу 10 объектов типа в Куче нужно написать так:

        Cat* p = new Cat[10];

    При этом у каждого объекта вызовется конструктор по умолчанию.
    Для того, чтобы удалить все 10 объектов из Кучи, нужно написать:

        delete[] p;


    !!  Операторы new/delete и new[]/delete[] это разные операторы. 
        Если вы их смешаете (например создадите объекты с помощью new[], а удалите с помощью delete),
        то это приведёт к ошибке - неопределённому поведению.
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
    Cat* p = new Cat[10];

}




/*
    Задачи:

        1)  Удалите массив объектов с помощью оператора delete[]

        2)  В каком порядке вызываются деструкторы объектов?
*/