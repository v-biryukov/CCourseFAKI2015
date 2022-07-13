/*
    До этого момента поля x и y класса Point были публичными

    Обычно, мы не хотим делать поля публичными, так как мы не хотим, чтобы поля могли бы быть заданы некоректным значением извне класса.
    Однако, в случае класса Point некорректных значений для x и y просто не существует - любое вещественное число будет
    корректным для значения координаты точки.
    Поэтому нет ничего плохого, чтобы сделать x и y публичными для класса Point


    Но давайте сделаем класс с немного более сложным поведением.
    Точка RestrictedPoint - это будет точка, которая может находится только в квадрате [0,1]x[0,1]
    То есть поле x может принимать значения только от 0 до 1 и поле y может принимать значения только от 0 до 1.

    Сделаем поля x и y приватными (и назовём их mx и my)
    Теперь до них можно будет доступиться только в методах класса RestrictedPoint и в друзьях.
    
    Чтобы можно было работать с этими полями вне класса напишем методы
        getx, gety, setx, sety
    Такие методы для получения полей и записи в поля класса называются геттерами и сеттерами
    Функции getx и gety просто возвращают соответствующие координаты
    Функции setx и sety меняют соответствующие координаты и следят, чтобы они находились в диапазоне от 0 до 1


    Нам понадобится стандартная функция std::clamp из <algorithm>, которая принимает на вход три числа и
        если первое число находится в промежутке между вторым и третьим, то clamp возвращает первое число
        если первое число меньше, чем второе, то clamp возвращает второе число
        если первое число больше, чем третье, то clamp возвращает третье число
    Грубо говоря clamp ограничивает число в заданых пределах
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using std::cout, std::endl;



class RestrictedPoint 
{
private:
    float mx, my;

public:

    RestrictedPoint(float x, float y)
    {
        mx = std::clamp(x, 0.0f, 1.0f);
        my = std::clamp(y, 0.0f, 1.0f);
    }

    RestrictedPoint()
    {
        mx = 0;
        my = 0;
    }

    float getx() const 
    {
        return mx;
    }

    float gety() const 
    {
        return my;
    }

    void setx(float x) 
    {
        mx = std::clamp(x, 0.0f, 1.0f);
    }

    void sety(float y) 
    {
        my = std::clamp(y, 0.0f, 1.0f);
    }

    float norm() const 
    {
        return std::sqrt(mx*mx + my*my);
    }

    RestrictedPoint operator+(const RestrictedPoint& right) const 
    {
        RestrictedPoint result;
        result.mx = std::clamp(mx + right.mx, 0.0f, 1.0f);
        result.my = std::clamp(my + right.my, 0.0f, 1.0f);
        return result;
    }
};


std::ostream& operator<<(std::ostream& out, const RestrictedPoint& a) 
{
    out << "(" << a.getx() << ", " << a.gety() << ")";
    return out;
}


int main() 
{
    RestrictedPoint a = RestrictedPoint(0.5, 1.2);
    cout << a << endl;

    a.setx(2);
    cout << a << endl;

    a.sety(-5);
    cout << a << endl;


    RestrictedPoint b = RestrictedPoint(0.4, 0.2);
    RestrictedPoint c = RestrictedPoint(0.8, 0.4);
    cout << c + b << endl;
}




/*
    Задача:

        1)  Добавьте к классу RestrictedPoint оператор умножения на число типа float

*/