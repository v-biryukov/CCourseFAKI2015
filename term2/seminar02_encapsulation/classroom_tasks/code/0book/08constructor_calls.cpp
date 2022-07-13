/*
    Синтаксис инициализации с помощью коструктора

    Язык C++ имеет очень длинную историю и на её протяжении в язык добавлялись новые возможности
    В итоге в языке часто можно сделать одно и то же разными методами.

    В частности, вызвать конструктор можно 5-ю разными способами.
    В этой программе строки для создания книг a, b, c, d, e делают одно и то же, несмотря, что имеют разный синтаксис
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

    Book d = Book{"War and Peace", 1000, 500};

    Book e {"War and Peace", 1000, 500};

    a.print();
    b.print();
    c.print();
    d.print();
    e.print();
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

            Создайте с помощью этого конструктора 5 книг, вызвав его 5-ю разными способами

*/
