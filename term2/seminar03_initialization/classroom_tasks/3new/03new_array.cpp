/*
    Операторы new[] и delete[]

    С помощью оператора new[] можно сразу создать массив из объектов в Куче.
    Чтобы создать сразу 10 объектов типа в Куче нужно написать так:

        Verbose* p = new Verbose[10];

    При этом у каждого объекта вызовется конструктор по умолчанию.
    Для того, чтобы удалить все 10 объектов из Кучи, нужно написать:

        delete[] p;


    Можно сразу инициализировать все эти объекты, используя круглые или фигурные скобочки:

        Verbose* pb = new Verbose[3] {"Alice"s, "Anna"s, "Alex"s};


    !!  Операторы new/delete и new[]/delete[] это разные операторы. 
        Если вы их смешаете (например создадите объекты с помощью new[], а удалите с помощью delete),
        то это приведёт к ошибке - неопределённому поведению.
*/

#include <iostream>
#include <cstdlib>
#include <string>
using std::cout, std::endl;
using namespace std::string_literals;

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



int main()
{
    Verbose* pb = new Verbose[3] {"Alice"s, "Anna"s, "Alex"s};


    delete[] pb;

}




/*
    Задача:

        В каком порядке вызываются деструкторы объектов?
*/