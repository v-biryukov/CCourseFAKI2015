#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
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

        if (pages < 0)
        {
            pages = 0;
        }
    }

    Book()
    {
        cout << "Default Construtor" << endl;
        std::strcpy(title, "Default");
        price = 0;
        pages = 0;
    }

    Book(const Book& b)
    {
        cout << "Copy Construtor" << endl;
        std::strcpy(title, b.title);
        price = b.price;
        pages = b.pages;
    }



    void print() const
    {
        cout << title << ", price = " << price << ", pages = " << pages << endl << endl;
    }
};

int main() 
{
    Book a = {"War and Peace", 1700, 900};
    a.print();

    Book b = {a};
    b.print();

    Book c = a;
    b.print();
}
