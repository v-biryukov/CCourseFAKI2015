#include <stdio.h>

struct book
{
    char title[100];
    int pages;
    float price;
};
typedef struct book Book;

void print_book_info(Book b)
{
    printf("Book info:\n");
    printf("Title: %s\n", b.title);
    printf("Pages: %d\n", b.pages);
    printf("Price: %.2f roubles\n\n", b.price);
}

void change_price(Book* b, float new_price)
{
    b->price = new_price;
}

int main()
{
    Book x = {"The Martian", 412, 800.0};
    print_book_info(x);
    
    Book scifi_books[100] = {
        {"Don Quixote", 1205, 950.0},    
        {"The Dark Tower", 655, 500.0}, 
        {"Fahrenheit 451", 434, 700.0},
        {"The Day of the Triffids", 304, 450.0}
    };
    scifi_books[4] = x;
    
    print_book_info(scifi_books[1]);
    change_price(&scifi_books[1], 1000.0);
    print_book_info(scifi_books[1]);
}
