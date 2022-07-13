#include <iostream>
using std::cout, std::endl;

struct Book
{
    char title[50];
    int pages;
    float price;
};

void printBook(Book x)
{
    cout << x.title << " " << x.pages << " " << x.price << endl;
}

int main()
{
    Book a = {"War and Peace", 900, 1200};
    printBook(a);

    Book b;
    printBook(b);

    b = a;
    printBook(b);
    
}

