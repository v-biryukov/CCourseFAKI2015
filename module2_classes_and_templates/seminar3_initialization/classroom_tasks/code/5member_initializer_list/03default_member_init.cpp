/*
    Значения по умолчанию для полей класса

    Для каждого поля класса можно указать его значение по умолчанию в фигурных скобках.

    Если поле не будет инициализировано в списке инициализации конструктора, то оно будет инициализовано 
    этим значением по умолчанию.

    Задача:

        Что напечатает эта программа?
*/

#include <iostream>
#include <string>
using std::cout, std::endl;


class Cat
{
private:

    std::string mName {"Alice"};
    int mAge          {10};

public:

    Cat() : mAge(20), mName("Bob")
    {
    }

    Cat(const std::string name, int age) : mName{name}, mAge{age}
    {
    }

    void print() const
    {
        cout << "Name: " << mName << ", age: " << mAge << endl;
    }
};


int main()
{
    Cat a;
    a.print();

    Cat b("Bob", 20);
    b.print();
}