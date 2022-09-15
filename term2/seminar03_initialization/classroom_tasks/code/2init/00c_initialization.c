/*
    Инициализация в языке C
    
    По умолчанию объекты не инициализируются (в них будут храниться случайные значения):
    
        int  a1;
        int  b1[5];
        Book c1;

    Инициализация объектов:

        int  a2 = 3;
        int  b2[5] = {10, 20, 30, 40, 50};
        Book c2 = {"War and Peace", 900, 1200};
        Book c3 = {.title = "Harry Potter", .price = 150.0};
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

void print_array(int* array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        printf("%i ", array[i]);
    printf("\n");
}

int main()
{
    printf("No Initialization:\n");

    int  a1;
    int  b1[5];
    Book c1;


    printf("%i\n", a1);
    print_array(b1, 5);
    print_book(c1);


    printf("\nInitialization:\n");


    int  a2 = 3;
    int  b2[5] = {10, 20, 30, 40, 50};
    Book c2 = {"War and Peace", 900, 1200};

    printf("%i\n", a2);
    print_array(b2, 5);
    print_book(c2);


    Book c3 = {.title = "Harry Potter", .price = 150.0};
    print_book(c3);
}

