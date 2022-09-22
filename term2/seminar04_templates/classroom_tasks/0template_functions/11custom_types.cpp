/*
    Статический полиморфизм

    Особый интерес представляют шаблоны при работе с пользовательскими типами.
    Мы можем написать шаблонную функцию, которая будет работать сразу с множеством разных классов.

    В данном примере созданы 3 класса, описывающие вещи, которые можно купить в онлайн магазине: книга, фильм, игра.
    У этих классов есть совпадающие методы с общим названием.
    Мы можем писать шаблонные функции, использующие эти методы, и тогда в шаблонную функцию можно будет передавать
    объекты всех трёх классов.
    

    Например, шаблонная функция isMoreExpensive принимает 2 объекта и выясняет, кто из них дороже.
    Если бы мы сделали то же самое с помощью обычных методов, то нам бы пришлось написать в каждом классе
    по 2 метода isMoreExpensive, принимающие разные типы.
    
*/


#include <iostream>
using std::cout, std::endl;


class Book 
{
private:
    std::string mTitle      {};
    int         mNumPages   {};
    float       mPrice      {};

public:
    Book(std::string title, int numPages, float price) : mTitle{title}, mNumPages{numPages}, mPrice{price} {}

    float getPrice() const {return mPrice;}
    void  setPrice(float newPrice) { mPrice = newPrice;}
    std::string getTypeName() {return "Book";}

    void print() 
    {
        std::cout << getTypeName() << ": " << mTitle << ", number of pages = " 
                  << mNumPages << ", price = " << mNumPages;
    }
};


class Movie 
{
private:
    std::string mTitle       {};
    int         mRunningTime {};
    float       mRating      {};
    float       mPrice       {};

public:
    Movie(std::string title, int runningTime, float rating, float price) 
    : mTitle{title}, mRunningTime{runningTime}, mRating{rating}, mPrice{price} 
    {}

    float getPrice() const {return mPrice;}
    void  setPrice(float newPrice) { mPrice = newPrice;}
    std::string getTypeName() {return "Movie";}
    
    void print() 
    {
        std::cout  << getTypeName() << ": " << mTitle << ", running time = " << mRunningTime << 
                    ", rating = " << mRating << ", price = " << mPrice;
    }
};


class VideoGame 
{
private:
    std::string mTitle       {};
    float       mRating      {};
    float       mPrice       {};

public:
    VideoGame(std::string title, float rating, float price) : mTitle{title}, mRating{rating}, mPrice{price} {}

    float getPrice() const {return mPrice;}
    void  setPrice(float newPrice) { mPrice = newPrice;}
    std::string getTypeName() {return "VideoGame";}
    
    void print() 
    {
        std::cout  << getTypeName() << ": " << mTitle << ", rating = " << mRating << ", price = " << mPrice;
    }
};



template <typename T>
void printPrice(const T& a)
{
    cout << a.getPrice() << endl;
}



template <typename T, typename U>
bool isMoreExpensive(const T& a, const U& b)
{
    return a.getPrice() > b.getPrice();
}



int main()
{
    Book a  {"Harry Potter", 400, 500};
    Movie b {"Interstellar", 240, 8.8, 700};
    VideoGame c {"Half-life 2", 9.1, 400};


    printPrice(a);
    printPrice(b);
    printPrice(c);

    cout << std::boolalpha;
    cout << isMoreExpensive(a, b) << endl;
    cout << isMoreExpensive(b, c) << endl;
    cout << isMoreExpensive(c, a) << endl;

    
}



/*
    Задачи:

        1)  Что напечатает данная программа

        2)  Напишите шаблонную функцию void changePrice(T& x, float value), которая будет принимать на вход 
            объект и увеличивает цену на value рублей.
 
*/