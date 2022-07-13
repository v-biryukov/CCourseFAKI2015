/*
    Синтаксис инициализации с помощью коструктора

    Язык C++ имеет очень длинную историю и на её протяжении в язык добавлялись новые возможности
    В итоге в языке часто можно сделать одно и то же разными методами

    В частности, вызвать конструктор можно 4-мя разными способами.
    В этой программе строки для создания книг a, b, c, d делают одно и то же, несмотря, что имеют разный синтаксис

*/

#include <iostream>
#include <cmath>
#include <string.h>
#include <cstdlib>
using std::cout, std::endl;


struct Book 
{
private:
    char title[100];
    float price;
    int pages;

public:
    Book(const char aTitle[], float aPrice, int aPages)
    {
        cout << "Constructor" << endl;
        strcpy(title, aTitle);
        price = aPrice;
        pages = aPages;
    }

    Book()
    {
        cout << "Default Constructor" << endl;
        strcpy(title, "default");
        price = 0;
        pages = 0;
    }


    void print() const
    {
        cout << title << ", price = " << price << ", pages = " << pages << endl;
    }
};



int main() 
{
    Book a = Book();

    // Book b();  // этот способ не работает, так как его невозможно отличить от объявления функции (зато добавился способ f)

    Book c = {};

    Book d = Book{};

    Book e {};

    Book f;     // в отличии от переменных базовых типов, тут произойдёт инициализация (конструктором по умолчанию)

    a.print();
    c.print();
    d.print();
    e.print();
    f.print();
}


