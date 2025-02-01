/*
    При перемещении объектов классов конструктор перемещения в некоторых случаях создаётся автоматически.
    Более подробно об этом позже.
*/

#include <vector>
#include <iostream>
using std::cout, std::endl;

struct Book
{
private:
    std::string title;
    int pages;
    float price;

public:
    Book(std::string title, int pages, float price) : title{title}, pages{pages}, price{price} {}
    friend std::ostream& operator<<(std::ostream& out, const Book& b);
};

std::ostream& operator<<(std::ostream& out, const Book& b)
{
    out << b.title << "," << b.pages << "," << b.price;
    return out;
}

int main()
{

    Book b1 {"War and Peace", 1200, 900};
    Book b2 = std::move(b1);
    cout << "Book 1: " << b1 << endl;
    cout << "Book 2: " << b2 << endl;
}