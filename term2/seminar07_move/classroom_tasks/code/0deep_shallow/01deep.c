/*
    Пример глубокого копирования в языке C
    !! Эта программа на языке C, для её компиляции нужно использовать компилятор gcc:       gcc 01deep.c

    Хотелось бы, чтобы при копировании объекта копировались не только поля, хранящиеся в самом объекте,
    но и все связанные с этим объектом данные.
    Никакой встроенной в язык C возможности это сделать нет, но мы можем написать такую функцию сами.

    В этом примере написана функция book_deep_copy, которая копирует не только поля структуры Book, но и
    память, с ней связанную. 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book
{
    char* title;
    int pages;
    float price;
};
typedef struct book Book;


Book book_create(const char* atitle, int apages, float aprice)
{
    Book result;
    result.pages = apages;
    result.price = aprice;

    int title_length = strlen(atitle);
    result.title = (char*)malloc((title_length + 1) * sizeof(char));
    strcpy(result.title, atitle);

    return result;
}

void book_print(const Book* x)
{
    printf("Title: %s, pages: %i, price: %.2f\n", x->title, x->pages, x->price);
}


Book book_deep_copy(const Book* x)
{
    Book result;
    result.pages = x->pages;
    result.price = x->price;

    int title_length = strlen(x->title);
    result.title = (char*)malloc((title_length + 1) * sizeof(char));
    strcpy(result.title, x->title);

    return result;
}


int main()
{
    printf("Book b is copy of Book a:\n");

    Book a = book_create("Harry Potter", 500, 200);
    printf("a) ");
    book_print(&a);

    Book b = book_deep_copy(&a);
    printf("b) ");
    book_print(&b);


    printf("\nChanging price of book b:\n");

    b.price = 700;
    printf("a) ");
    book_print(&a);
    printf("b) ");
    book_print(&b);



    printf("\nChanging title of book b:\n");

    b.title[0] = 'B';
    printf("a) ");
    book_print(&a);
    printf("b) ");
    book_print(&b);



    free(a.title);
    free(b.title);
}



/*
    Задача:

        Попробуйте понять, что напечатает данная программа.
        Проверьте себя, скомпилировав и запустив программу.




    Схему объектов в памяти данной программы можно представить следующим образом:

            a
           ╔═══════════╗                   ╔════════════════════════════╗
           ║     *─────╫────────────────── ║        Нarry Potter        ║
           ╟───────────╢                   ╚════════════════════════════╝
           ║    500    ║                  
           ╟───────────╢                  
           ║    240    ║                  
           ╚═══════════╝                  
                                          

            b
           ╔═══════════╗                   ╔════════════════════════════╗
           ║     *─────╫────────────────── ║        Barry Potter        ║
           ╟───────────╢                   ╚════════════════════════════╝
           ║    500    ║
           ╟───────────╢
           ║    777    ║
           ╚═══════════╝

*/