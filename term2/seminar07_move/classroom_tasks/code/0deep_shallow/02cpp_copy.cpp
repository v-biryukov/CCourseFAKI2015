/*
    В языке C++ то, что происходит при копировании объектов, можно прописать самостоятельно
    в конструкторе копирования и перегруженном операторе присваивания.
    Как правило, в конструкторе копирования и перегруженном операторе присваивания прописывается глубокое копирование.


    В этом примере код из предыдущего примера переписан с языка C на язык C++.
    Копирование объекта прописывается в конструкторе копирования Book(const Book& b).
    Видно, что в этом методе прописано именно глубокое копирование.
    В функции main, в строке:

        Book b = a;

    для копирования объекта a в объект b вызывается именно этот конструктор копирования.
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using std::cout, std::endl;

struct Book
{
private:
    char* title;
    int pages;
    float price;

public:

    Book(const char* atitle, int apages, float aprice) : pages {apages}, price {aprice}
    {
        int title_length = std::strlen(atitle);
        title = new char[title_length + 1];
        std::memcpy(title, atitle, title_length + 1);
    }

    Book(const Book& b) : pages {b.pages}, price {b.price}
    {
        int title_length = std::strlen(b.title);
        title = new char[title_length + 1];
        std::memcpy(title, b.title, title_length + 1);
    }


    Book& operator=(const Book& b)
    {
        if (this == &b)
            return *this;

        pages = b.pages;
        price = b.price;

        delete [] title;

        int title_length = std::strlen(b.title);
        title = new char[title_length + 1];
        std::memcpy(title, b.title, title_length + 1);

        return *this;
    }


    void setPrice(float newPrice)
    {
        price = newPrice;
    }

    void changeFirstLetter(char c)
    {
        title[0] = c;
    }

    ~Book()
    {
        delete [] title;
    }

    friend std::ostream& operator<<(std::ostream& out, const Book& b);
};

std::ostream& operator<<(std::ostream& out, const Book& b)
{
    out << "Title: " << b.title << ", pages: " << b.pages << ", price " << b.price;
    return out;
}




int main()
{
    cout << "Book b is copy of Book a:" << endl;
    Book a {"Harry Potter", 500, 200};
    Book b = a;
    cout << "a) " << a << endl;
    cout << "b) " << b << endl;


    cout << endl << "Changing price of book b:" << endl;
    b.setPrice(700);
    cout << "a) " << a << endl;
    cout << "b) " << b << endl;


    cout << endl << "Changing title of book b:" << endl;
    b.changeFirstLetter('B');
    cout << "a) " << a << endl;
    cout << "b) " << b << endl;
}