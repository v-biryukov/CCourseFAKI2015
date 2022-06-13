#include <iostream>
#include <cmath>
#include <string.h>
#include <cstdlib>
using std::cout, std::endl;


/*
    Синтаксис инициализации с помощью коструктора

    Язык C++ имеет очень длинную историю и на её протяжении в язык добавлялись новые возможности
    В итоге в языке часто можно сделать одно и то же разными методами

    В частности, вызвать конструктор можно 4-мя разными способами.
    В этой программе строки для создания книг a, b, c, d делают одно и то же, несмотря, что имеют разный синтаксис

*/


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


    void print() const
    {
        cout << title << ", price = " << price << ", pages = " << pages << endl;
    }
};



int main() 
{
    Book a = Book("War and Peace", 1000, 500);

    Book b("War and Peace", 1000, 500);

    Book c = {"War and Peace", 1000, 500};

    Book d {"War and Peace", 1000, 500};

    a.print();
    b.print();
    c.print();
    d.print();
}

/*
    Задача:

        1)  Добавьте к классу конструктор по умолчанию:

                Book()
                {
                    cout << "Default Constructor" << endl;
                    strcpy(title, "default");
                    price = 0;
                    pages = 0;
                }

            Создайте с помощью этого конструктора 4 книги, вызвав его 4-мя разными способами

*/
