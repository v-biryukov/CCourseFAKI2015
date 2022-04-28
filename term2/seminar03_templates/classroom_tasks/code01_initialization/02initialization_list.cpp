#include <iostream>
#include <string>
using std::cout, std::endl;


/* 

    Список инициализации

    В конструкторе можно инициалицировать поля класса с помощью специального синтаксиса
    Нужно поставить : (точку с запятой) после списка аргументов и инициализировать поля класса


*/



// Простой класс с перегруженным дружественным оператором  ostream << Point
class Book 
{
private:
    std::string title;
    int pages;
    float price;

public:

    Book(std::string atitle, int apages, float aprice) : title {atitle}, pages {apages}, price {aprice}
    {
    }


    friend std::ostream& operator<<(std::ostream& left, const Book& right);
};

std::ostream& operator<<(std::ostream& left, const Book& right) 
{
    left << right.title << ", pages: " << right.pages << ", price: " << right.price;
    return left;
}





int main() 
{
    Book b {"War and Peace", 1200, 900};
    cout << b << endl;
}



/*

    В чём различие в между следующими двумя конструкторами?

    Book(std::string atitle, int apages, float aprice) : title {atitle}, pages {apages}, price {aprice}
    {
    }


    Book(std::string atitle, int apages, float aprice)
    {
        title = atitle;
        pages = apages;
        price = aprice;
    }



*/