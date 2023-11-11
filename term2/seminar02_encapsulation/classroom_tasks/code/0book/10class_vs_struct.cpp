/*
    Различие между ключевыми словоами struct и class.

    Разница между этими ключевым словами минимальна:

        - при использовании struct поля и методы по умолчанию публичны
        - при использовании class  поля и методы по умолчанию приватны

    Если указывать private и public для всех членов, то разницы нет вообще.

    Есть ещё одно маленькое отличие struct от class, связанное с наследованием, его мы пройдём позже.
*/

#include <iostream>
#include <cmath>
#include <string.h>
#include <cstdlib>
using std::cout, std::endl;


struct SPoint
{
    // Поля x и y тут будут публичными
    float x;
    float y;

public:

    SPoint(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    void print() const
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};


class CPoint
{
    // Поля x и y тут будут приватными
    float x;
    float y;

public:

    CPoint(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    void print() const
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};


int main() 
{
    SPoint a {10, 20};
    a.x = 30; // OK
    a.print();


    CPoint b {10, 20};
    // b.x = 30; // Ошибка
    b.print();
}
