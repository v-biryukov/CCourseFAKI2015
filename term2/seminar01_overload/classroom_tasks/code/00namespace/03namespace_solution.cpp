#include <cstdio>


namespace mipt 
{
    struct Book 
    {
        char title[50];
        int pages;
        float price;
    };

    void printBook(Book b)
    {
        printf("%s, pages: %d, price: %.2f\n", b.title, b.pages, b.price);
    }
}



int main() 
{
    mipt::Book b = {"War and Peace", 1200, 900};
    mipt::printBook(b);
}

/*
    Задание:

    Структура Book и функция printBook определены в пространстве имён mipt

    1)  Создайте переменную типа структура Book и иницилизируйте
        её значениями: "War and Peace", 1200, 900

    2)  Напечатайте созданную переменную с помощью функции printBook
*/