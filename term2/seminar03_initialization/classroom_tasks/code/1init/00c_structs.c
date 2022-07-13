/*
    



*/



#include <stdio.h>

struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(Book x)
{
    printf("%s %i %f\n", x.title, x.pages, x.price);
}

int main()
{
    Book a = {"War and Peace", 900, 1200};
    print_book(a);

    Book b;
    print_book(b);

    b = a;
    print_book(b);
}

