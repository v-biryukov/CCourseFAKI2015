#include <iostream>
#include <vector>
#include <algorithm>

// Подключаем std::function
#include <functional>

using std::cout;
using std::endl;


struct Book
{
    std::string title;
    int number_of_pages;
    float price;
};

// Вспомагательная функция, для печати одной книги
std::ostream& operator<<(std::ostream& stream, const Book& b)
{
    stream << b.title << ".\n\t\t Pages: " << b.number_of_pages << ".\t Price: " << b.price;
    return stream;
}

// Вспомагательная функция, для печати вектора книг
void print_books(const std::vector<Book>& books)
{
    cout << "\nBook array: " << endl;
    for (const Book& b : books)
    {
        std::cout << b << endl;
    }
}

int main()
{
    // Создадим вектор из книг:
    std::vector<Book> books {
        {"Harry Potter and the Philosopher's Stone", 450, 600},
        {"Lord of the Flies", 224, 420},
        {"One Hundred Years of Solitude", 550, 780},
        {"War and Peace", 1260, 1000},
        {"A Game of Thrones", 694, 1200},
        {"In Search of Lost Time", 4215, 2000},
        {"Crime and Punishment", 700, 800},
        {"The Catcher in the Rye", 234, 280}
    };

    print_books(books);

    // Сортируем книги по цене с помощью лямбда функции
    std::sort(books.begin(), books.end(), [](Book a, Book b) {return a.price < b.price;});
    print_books(books);


    /* Задания:
        1) Отсортируйте все книги по количеству страниц, от больших к менишим и напечатайте
        2) Отсортируйте все книги по названию и напечатайте
        
        3) Подсчитайте все книги, которые стоят менее 700 рублей и напечатайте их
           Используйте функцию count_if

        4) Увеличьте стоимость каждой книги на 100, используя функцию std::for_each

    */

}