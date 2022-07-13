/*
    Ключевое слово this

    Используя указатель this внутри структуры, можно узнать адрес объекта.
    Например, если метод был вызван таким образом:
        a.printThis();
    то внутри метода this будет означать адрес объекта a

    С помощью этого указателя можно доступаться до полей класса.
    Например,  title  и  this->title  это одно и то же внутри методов структуры.

    this можно использовать, если имя аргумента метода совпадает с одним из полей, как, например, в методе setPrice
    Внутри метода setPrice поле price перекрывается аргументом price. Но можно всё-равно доступиться до поля price, используя указатель this
*/

#include <iostream>
using std::cout, std::endl;


struct Book 
{
    char title[100];
    float price;
    int pages;

    void printThis() const
    {
        cout << this << endl;
    }

    void printTitle() const
    {
        cout << title << endl;
        cout << this->title << endl;
    }

    void setPrice(float price)
    {
        this->price = price;
    }
};


int main() 
{
    Book a = {"War and Peace", 1700, 900};

    cout << &a << endl;
    a.printThis();

    a.printTitle();
}

