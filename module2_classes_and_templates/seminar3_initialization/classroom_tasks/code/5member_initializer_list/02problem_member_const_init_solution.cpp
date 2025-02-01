/*
    Решение:

        Проблема была в том, что константам нельзя ничего присваивать. Например:

            const int a = 10; // ОК, инициализируем a значением 10.
            a = 20; // Ошибка, константы нельзя менять. Присваивание для них не работает.

        Соответственно в этой задаче ошибка была в том, что внутри конструктора константному
        полю mName присваивалось другое значение.
        Проблему можно решить, если инициализировать поле с помощью списка инициализации.
*/

#include <iostream>
#include <string>
using std::cout, std::endl;


class Cat
{
private:

    const std::string mName;

public:

    Cat(const std::string& name) : mName{name}
    {   
    }

    void print() const
    {
        cout << mName << endl;
    }
};


int main()
{
    Cat a("Alice");
    a.print();
}