/*
    Некоторые замечания по оформлению

    1)  Как правило в классе сначала описываются публичные методы, а потом приватные
        Так делают потому что если другой программист захочет воспользоваться вашим классом,
        то его будет в первую очередь будет интересовать что ваш класс может делать
        и уже потом его будет интересовать строение класса.


    2)  Приватные поля класса желательно называть так, чтобы их можно было отличить от обычных переменных
        Это может сильно упростить понимание при написании/использовании больших програм и библиотек
        В данном курсе мы будем называть приватные поля начиная с буквы m
        Например,  mTitle  вместо  title
*/

#include <iostream>
#include <cmath>
#include <string.h>
#include <cstdlib>
using std::cout, std::endl;


class Book 
{
public:
    Book(const char title[], float price, int pages)
    {
        if (pages < 0 || price < 0 || strlen(title) >= 100)
        {
            cout << "Error while creating Book!" << endl;
            std::exit(1);
        }

        strcpy(mTitle, title);
        mPrice = price;
        mPages = pages;
    }

    void print() const
    {
        cout << mTitle << ", price = " << mPrice << ", pages = " << mPages << endl;
    }

private:
    char mTitle[100];
    float mPrice;
    int mPages;
};



int main() 
{
    Book a = Book("War and Peace", 1700, 900);
    a.print();
}
