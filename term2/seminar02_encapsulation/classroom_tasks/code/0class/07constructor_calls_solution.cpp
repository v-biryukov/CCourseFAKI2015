#include <iostream>
#include <cmath>
#include <string.h>
#include <cstdlib>
using std::cout, std::endl;


struct Book 
{
    char title[100];
    float price;
    int pages;

    Book(const char aTitle[], float aPrice, int aPages)
    {
        cout << "Constructor" << endl;
        std::strcpy(title, aTitle);
        price = aPrice;
        pages = aPages;
    }

    Book()
    {
        cout << "Default Constructor" << endl;
        std::strcpy(title, "default");
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

    // Book b();  // этот способ не работает, так как его невозможно отличить от объявления функции (зато добавился способ f).

    Book c = Book{};

    Book d = {};

    Book e {};

    Book f;     // тут тоже вызовется конструктор по умолчанию.

    a.print();
    c.print();
    d.print();
    e.print();
    f.print();
}


