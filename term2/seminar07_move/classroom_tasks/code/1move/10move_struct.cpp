/*
    Перемещение структур

    При перемещении структрур, перемещаются все её поля.

    
    Задача:

        Что напечатает данная программа?

*/

#include <vector>
#include <iostream>
#include <utility>
using std::cout, std::endl;

struct Date
{
    int day, month, year;
};

std::ostream& operator<<(std::ostream& out, Date d)
{
    out << d.day << "." << d.month << "." << d.year;
    return out;
}

struct Book
{
    std::string title;
    int pages;
    float price;
};

std::ostream& operator<<(std::ostream& out, const Book& b)
{
    out << b.title << "," << b.pages << "," << b.price;
    return out;
}

int main()
{
    Date d1 = {5, 6, 2008};
    Date d2 = std::move(d1);

    cout << "Date 1: " << d1 << endl;
    cout << "Date 2: " << d2 << endl << endl;



    Book b1 = {"War and Peace", 1200, 900};
    Book b2 = std::move(b1);

    cout << "Book 1: " << b1 << endl;
    cout << "Book 2: " << b2 << endl;
}