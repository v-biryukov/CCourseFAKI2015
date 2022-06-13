#include <iostream>



/*
    Эта программа написана на языке C++, для компиляции используйте g++:
        g++ 01book.cpp

    В языке C++ появились ссылки, которые можут немного упростить код из предыдущего файла
    
    Однако, структура и функции для работы с ней всё ещё являются независимыми
    То есть тут тоже нет Инкапсуляции.

*/


struct Book 
{
    char title[100];
    float price;
    int pages;
};


void makeDiscount(Book& b, int discount) 
{
    if (b.price > discount)
        b.price -= discount;
    else
        b.price = 0;
}

void printBook(const Book& b) 
{
    std::cout << b.title << ", price = " << b.price << ", pages = " << b.pages << std::endl;
}



int main() 
{
    Book b = {"War and Peace", 1700, 900};

    printBook(b);
    makeDiscount(b, 500);
    printBook(b);
}
