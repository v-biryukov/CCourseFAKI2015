/*
    Сокрытие данных. public и private.

    Сокрытие данных - это разделение данных и функций абстрактного объекта на открытые (видимые извне) и скрытые 
    (видимые только внутри самого объекта) В языке C++ это реализуется с помощью модификаторов доступа public и private.

    Все поля и методы объявленные в секции public называются публичными и могут быть доступны извне структуры.
    Все поля и методы объявленные в секции private называются приватными и не могут быть доступны извне структуры.
    Приватные поля и методы могут быть доступны только в методах самой структуры (а также в друзьях, но об этом позже).


    Назначение сокрытия данных заключается в том, чтобы объекты нельзя было 'поломать' извне.
    'Поломать' тут означает задать поля объекта бессмысленным образом.

    Например, в нашем примере мы бы могли поломать объект просто сделав поля price или pages отрицательными:

        a.pages = -100;

    но благодаря тому, что поле pages является приватным, это сделать нельзя.


    Учитывая проверку в конструкторе, получается, что поля pages и price в принципе никогда не смогут стать отрицательными.
    Таким образом мы уберегли себя от возникновения ошибок при неправильном задании полей структуры.
*/

#include <iostream>
#include <cmath>
#include <string.h>
#include <cstdlib>
using std::cout, std::endl;


struct Book 
{
private:
    char title[100];
    float price;
    int pages;

public:
    Book(const char aTitle[], float aPrice, int aPages)
    {
        if (aPages < 0 || aPrice < 0 || strlen(aTitle) >= 100)
        {
            cout << "Error while creating Book!" << endl;
            std::exit(1);
        }

        strcpy(title, aTitle);
        price = aPrice;
        pages = aPages;
    }


    void print() const
    {
        cout << title << ", price = " << price << ", pages = " << pages << endl;
    }
};



int main() 
{
    Book a = Book("War and Peace", 1700, 900);
    a.print();

    a.pages = -100;
}
