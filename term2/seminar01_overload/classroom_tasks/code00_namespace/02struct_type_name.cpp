#include <stdio.h>

/*
    В языке C   при объявлении структуры struct Book создаётся тип по имени struct Book. 

    В языке C++ при объявлении структуры struct Book создаётся тип к которому
    можно обращаться как по имени struct Book так и по имени Book
*/


struct Book 
{
    char title[50];
    int pages;
    float price;
};


int main() 
{
    struct Book a = {"Tom Sawyer", 280, 500};

    Book b = {"War and Peace", 1200, 900};
}
