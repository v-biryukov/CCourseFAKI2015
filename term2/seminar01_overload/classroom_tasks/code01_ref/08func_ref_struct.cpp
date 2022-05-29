#include <iostream>
using std::cout, std::endl;


/*
    Чаще всего по ссылке в функцию передаются объекты структур и классов

    Даже если мы не хотим менять объект внутри функции, мы всё-равно можем
    захотеть передать его по ссылке, так как передача по ссылке не копирует объект,
    следовательно это гораздо более эффективно

    В этом случае передаём по константной ссылке (по аналогии с константным указателем)

*/


struct Book
{
    char title[100];
    int pages;
    float price;
};


void increasePrice(Book& b, float value)
{
    b.price += value;
}

void printBook(Book& b)
{
    cout << b.title << ", pages = " << b.pages << ", price = " << b.price << endl;
}


int main() 
{
    Book b = {"War and Peace", 1200, 900};

    printBook(b);
    increasePrice(b, 100);
    printBook(b);
}


/*
// Тот же самый код с использованием указателей выглядел бы так:

void increasePrice(Book* b, float value)
{
    b->price += value;
}

void printBook(const Book* b)
{
    cout << b->title << ", pages = " << b->pages << ", price = " << b->price << endl;
}

int main() 
{
    Book b = {"War and Peace", 1200, 900};

    printBook(&b);
    increasePrice(b, 100);
    printBook(&b);
}

*/


/*
    Задачи:

    1)  Напишите функцию addPage, которая бы принимала структуру Book по ссылке
        и увеличивала количество страниц на 1
        Протестируйте эту функцию в main

    2)  Напишите функцию changeFirstLetter, которая бы принимала структуру Book по ссылке
        и изменяла первую букву в названии на букву A

*/