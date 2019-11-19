#include <stdio.h>
#include <string.h>

struct book
{
    char title[100];
    int pages;
    float price;
}; // <------ не забывайте точку с запятой в конце описания структуры
typedef struct book Book;


// Структуры передаются в функции также как и обычные переменные
void print_book(Book a)
{
    printf("b: Title: %s | Pages: %d | Price: %f\n", a.title, a.pages, a.price);
}

// Структуры возвращаются из функций также как и обычные переменные
Book get_war_and_peace()
{
    Book b = {"War and Peace", 1754,   72.0};
    return b;
}

// Функции также копируются при передаче как и обычные переменные (а не массивы)
// (Если массив находится внутри структуры - он тоже копируется, 
//        например массив title структуры Book копируется и внутри функции addfive_to_price_stupid его не изменить)
// Это работать не будет:
void addfive_to_price_stupid(Book a)
{
    a.price += 5;
}

// Чтобы изменить структуру в функции, вам нужно передавать указатель на неё:
// (также как и для обычных переменных)
void addfive_to_price(Book* p)
{
    (*p).price += 5;
}

// Вместо выражения (*p). можно использовать стрелочку ->
void addfive_to_price_2version(Book* p)
{
    p->price += 5;
}

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// Напишите функции из заданий тут:



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


int main()
{
    print_book(get_war_and_peace());

    Book a = get_war_and_peace();

    printf("\nAdd 5 to price stupid:\n");
    addfive_to_price_stupid(a);
    print_book(a);

    printf("\nAdd 5 to price:\n");
    addfive_to_price(&a);
    print_book(a);

    printf("\nAdd 5 to price 2 version:\n");
    addfive_to_price_2version(&a);
    print_book(a);


    /*
    --> Задание 1  - напишите функцию is_book_cheap,
    -->              которая принимает на вход Book
    -->              и возвращает 1, если цена книги меньше 200 р. и 0 если больше 200 р.
    -->              Раскомментируйте код ниже, когда напишите функцию
    */
    //if (is_book_cheap(a))
    //    printf("Book %s is cheap\n", a);





    /*
    --> Задание 2  - напишите функцию change_book_price,
    -->              которая принимает на вход указатель на Book и число float new_price
    -->              и изменяет цену книги
    -->              Используйте стрелочки ->        p->title и т.д.
    -->              Раскомментируйте код ниже, когда напишите функцию
    */
    //change_book_price(&a, 500); // Устанавливаем цену книги в 500 р.
    //print_book(a);



    /*
    --> Задание 3  - напишите функцию print_book_by_pointer,
    -->              которая принимает на вход указатель на Book и печатает книгу
    -->              Используйте стрелочки ->        p->title и т.д.
    -->              Вызовите функцию ниже
    -->              Чем эта функция лучше функции print_book?
    */


}