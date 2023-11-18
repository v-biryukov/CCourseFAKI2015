/*
    Классы. Ключевое слово class.

    На самом деле классы мы уже прошли. Структуры с методоми из предыдущих файлов это и есть классы.
    Для объявления класса может использоваться ключевое слово class.
*/

#include <iostream>
#include <cmath>
#include <string.h>
#include <cstdlib>
using std::cout, std::endl;

class Book
{
private:
    char title[100];
    float price;
    int pages;

public:
    Book(const char aTitle[], float aPrice, int aPages)
    {
        std::strcpy(title, aTitle);
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
    Book a("War and Peace", 1700, 900);
    a.print();
}
