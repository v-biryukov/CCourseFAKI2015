/*
    Инициализация статических полей в классах

    Инициализация статических полей в классах не так проста, как может показаться на первый взгляд.
    Инициализировать статическое поле прямо в классе, как это сделано в предыдущем файле с полем 
    numberOfSides, можно только в некоторых случаях. Для этого поле должно быть константным, иметь
    не слишком сложный тип и инициализироваться значением, известным на этапе компиляции.

    
    В общем же случае, инициалицировать такую переменную нужно вне класса.
    Инициализация такой переменной похожа на инициализацию глобальной переменной.

    В данном примере создаётся статическая переменная value в классе Rectangle:

        static int value;

    Затем она инициализируется вне класса:

        int Rectangle::value = 10;
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

    static int value;
};

int Rectangle::value = 10;



int main()
{
    cout << Rectangle::value << endl;

    Rectangle::value += 10;


    Rectangle a(1, 1);
    cout << Rectangle::value << endl;
    cout << a.value << endl;
}


/*
    Задача:

        Создайте в классе Rectangle статическое поле класса std::string.
        Инициализируйте это поле значением "Cat".
*/