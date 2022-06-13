#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using std::cout, std::endl;


struct Book 
{
    char title[100];
    float price;
    int pages;

    Book(const char aTitle[], float aPrice, int aPages)
    {
        cout << "Constructor" << endl;
        strcpy(title, aTitle);
        price = aPrice;
        pages = aPages;

        if (pages < 0)
        {
            cout << "Error! Number of pages can't be negative!" << endl;
            std::exit(1);
        }
    }

    Book()
    {
        cout << "Default Construtor" << endl;
        strcpy(title, "Default");
        price = 0;
        pages = 0;
    }


    Book(const Book& b)
    {
        cout << "Copy Construtor" << endl;
        strcpy(title, b.title);
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
    Book a = Book("War and Peace", 1700, 900);
    a.print();

    Book b = Book();
    b.print();

    Book c = Book(a);
    c.print();

    Book d = Book("The Great Gatsby", 800, -600);
    d.print();

}
