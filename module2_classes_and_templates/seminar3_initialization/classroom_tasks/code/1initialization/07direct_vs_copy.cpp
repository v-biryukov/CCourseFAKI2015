/*
    Разница между direct и copy инициализацией

    Для скаляров и агрегатор разницы между direct и copy инициализациями нет.

    Для классов есть два важных отличия между direct и copy инициализациями классов.
    Рассмотрим эти различия на примере класса Book:

    1)  Copy-инициализация используется при передаче в функцию, которая принимает по значению,
        и при возврате из функции.

            Например, в строке:

                print({"Harry Potter", 500, 1000.0});

            происходит copy-инициализация параметра x внутри функции print.


    2)  Если необходимый конструктор помечен как explicit, copy-инициализация работать не будет.
        Будет просто ошибка компиляции.

            Убедитесь в этом, пометив конструктор класса Book как explicit.
            После этого строки:

                print({"Harry Potter", 500, 1000.0});

            и
                
                return {"One Hundred Years of Solitude", 1000, 2000.0};

            будут приводить к ошибкам компиляции.
*/

#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

class Book
{
private:
    std::string mTitle;
    int mPages;
    float mPrice;

public:

    /*explicit*/ Book(std::string title, int pages, float price)
    {
        mTitle = title;
        mPages = pages;
        mPrice = price;
    }

    std::string getTitle() const {return mTitle;}
    int getPages() const {return mPages;}
    float getPrice() const {return mPrice;}
};


void print(Book x)
{
    cout << x.getTitle() << ", pages = " << x.getPages() << ", price = " << x.getPrice() << endl;
}


Book get()
{
    return {"One Hundred Years of Solitude", 1000, 2000.0};
}


int main()
{
    print({"Harry Potter", 500, 1000.0});

    Book a = get();
    print(a);
}