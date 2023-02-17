#include <iostream>
using std::cout, std::endl;

struct Book
{
    char title[100];
    int pages;
    float price;
};

void addPage(Book& b)
{
    b.pages++;
}

void changeFirstLetter(Book& b)
{
    b.title[0] = 'A';
}

void printBook(const Book& b)
{
    cout << b.title << ", pages = " << b.pages << ", price = " << b.price << endl;
}


int main() 
{
    Book b = {"War and Peace", 1200, 900};

    printBook(b);

    addPage(b);
    printBook(b);

    changeFirstLetter(b);
    printBook(b);
}

