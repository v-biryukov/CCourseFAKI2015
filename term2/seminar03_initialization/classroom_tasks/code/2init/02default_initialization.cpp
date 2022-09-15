/*
    Default initialization

    Выглядит вот так:

        type a;

    Объекты инициализируются так:
    
        1)  Обычные типы - не инициализируются

        2)  Классы - вызывается конструктор по умолчанию, если его нет, то ошибка.

        3)  Агрегаты - каждый элемент агрегата инициализируется по умолчанию 
                                        
*/

#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

struct Book
{
    string title;
    int pages;
    float price;
};

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
    void say(){cout << "Meow, I am " << mname << endl;}
};




int main()
{
    int a; // обычный
    
    Cat b; // класс

    Book c; // агрегат

    Cat d[5]; // агрегат
}

