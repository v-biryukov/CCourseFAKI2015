/*
    Статические поля в классах

    Можно создавать статические поля в классах. Такие поля инициализируются в самом начале работы 
    программы (до функции main) и уничтожаются в самом конце (после функции main).

    Такие поля хранятся в сегменте данные, а не в самом объекте. Таким образом, размер объекта
    не увеличится, если вы создадите в нём новое статическое поле.
    Значение статического поля - общее для всех объектов данного класса.
    Получить значение этого поля, можна как через переменную этого класса:

        Rectangle a(10, 20);
        cout << a.numberOfSides << endl;

    так и просто через сам класс (ведь значение этого поля общее для всех объектов данного класса):

        cout << Rectangle::numberOfSides << endl;

*/

#include <iostream>
#include <string>
using std::cout, std::endl;



class Rectangle
{
private:

    float mWidth;
    float mHeight;

public:

    Rectangle(float width, float height)
    {
        mWidth = width;
        mHeight = height;
    }

    const static int numberOfSides = 4;
};


int main()
{
    Rectangle a(10, 20);

    cout << Rectangle::numberOfSides << endl;
    cout << a.numberOfSides << endl;

    cout << sizeof(a) << endl; // numberOfSides не хранится внутри a
}
