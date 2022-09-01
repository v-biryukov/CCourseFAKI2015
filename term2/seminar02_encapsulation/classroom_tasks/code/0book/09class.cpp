/*
    Классы. Ключевое слово class.

    На самом деле классы мы уже прошли. Структуры с методоми из предыдущих файлов это и есть классы.
    Для объявления класса может использоваться ключевое слово class.

    Разница между этими ключевым словами минимальна
        - при использовании struct все поля и методы по умолчанию публичны
        - при использовании class  все поля и методы по умолчанию приватны
    Но, так как  мы указываем private и public для всех членов, то разницы нет вообще.
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
        if (aPages < 0 || aPrice < 0 || strlen(aTitle) >= 100)
        {
            cout << "Error while creating Book!" << endl;
            std::exit(1);
        }

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
    Book a = Book("War and Peace", 1700, 900);
    a.print();
}
