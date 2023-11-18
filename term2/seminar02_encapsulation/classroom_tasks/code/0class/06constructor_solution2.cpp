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
        std::strcpy(title, "Cats and Dogs");
        price = 100;
        pages = 100;
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

    Book d = {"The Great Gatsby", 800, -600};
    d.print();

}
