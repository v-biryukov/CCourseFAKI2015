/*
    Оператор стрелочка

    Указатели на структуры используются в программировании на языке C очень часто.
    Поэтому желательно, чтобы работать с ними можно было как можно более удобнее.

        Book a = {"The Martian", 300, 500};
        Book* p = &a;

    Чтобы доступиться до поля структуры по указателю на эту структуру нужно проделать 2 операции:
    разыменовать с помощью звёздочки и доступиться к полю структуры с помощью точки.

        (*p).price

    Это не совсем удобно, поэтому в языке C был введён оператор стрелочка (->) который позволяет сделать
    то же самое, но только за один шаг:

        p->price
        
    
    В итоге:

        a           - это сама структура
        p           - это указатель на структуру
        *p          - разыменование указателя, то есть *p это то же самое, что и a
        (*p).price  - это то же самое, что и a.price
        p->price    - это то же самое, что и (*p).price и a.price
*/

#include <stdio.h>

struct book 
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(struct book b) 
{
    printf("Book: %s, Pages: %i, Price: %g\n", b.title, b.pages, b.price);
}

int main() 
{
    Book a = {"The Martian", 300, 500};
    Book* p = &a;


    p->price += 100;


    print_book(a);
}

/*
    Задачи:

        1)  Используйте указатель p и оператор -> , чтобы увеличить количество страниц в книге a на 1.

        2)  Используйте указатель p и оператор -> , чтобы изменить букву 'M' в названии книги на букву 'B'
            То есть название книги должно изменится на "The Bartian"

        3)  Используйте указатель p и оператор -> , чтобы изменить название книги на "Harry Potter and the Philosopher's Stone"
*/