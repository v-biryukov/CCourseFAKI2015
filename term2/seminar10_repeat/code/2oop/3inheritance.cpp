#include <math.h>
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;

const float PI = 3.14159265;


// Абстрактный класс (или Интерфейс)
// Чтобы сделать класс абстрактным нужно просто один из его методов задать равным 0
class Shape
{
protected:
    float x, y;

public:
    Shape(float x0, float y0) : x(x0), y(y0) {}

    // Виртуальный метод
    virtual float get_perimeter() = 0;
};


// Окружность
class Circle : public Shape
{
protected:
    float radius;

public:
    // Конструктор окружности. Обратите внимание на вызов конструктора Shape()
    Circle(float x0, float y0, float radius0) : Shape(x0, y0), radius(radius0) {}

    float get_perimeter()
    {
        return 2 * PI * radius;
    }
};

// Правильный n-угольник
class RegularPolygon : public Shape
{
protected:
    int n;
    float radius;

public:
    RegularPolygon(float x0, float y0, int n, float radius0) : Shape(x0, y0), n(n), radius(radius0) {}
    float get_perimeter()
    {
        float side = 2 * radius * sin(PI/n);
        return n * side;
    }
};

// Квадрат
class Square : public RegularPolygon
{
public:
    Square(float x0, float y0, float size) : RegularPolygon(x0, y0, 4, size/sqrt(2.0)) {}
};



int main()
{
    // Можно ли выполнить следующую строку? Почему?
    // Shape s1 = {1.0, 5.0};

    // Окружность
    Circle c = {1, 5, 3};
    cout << "Circle: " << c.get_perimeter() << endl;

    // Правильный 100-угольник
    RegularPolygon reg100 = {0, 0, 100, 3};
    cout << "Reg100: " << reg100.get_perimeter() << endl;

    // Квадрат
    Square s = {0, 0, 3};
    // Будет ли правильно работать следующая строка?
    // Можно ли вызвать get_perimeter(), если он не определён в классе Square
    // cout << "Square: " << s.get_perimeter() << endl;

    // Задача 1:
    // Переопределите метод get_perimeter() в классе Square и вызовите его
    // Какие преемущества этого метода по сравнению с унаследованным
    // Чтобы точно знать какой метод вызывается сделайте так, чтобы они 
    // при вызове выводили на экран разные сообщения

    // Проверка:
    cout << "\nTesting Square:\n";

    Square s1 = Square(0, 0, 3);
    cout << s1.get_perimeter() << endl;

    Square* ps2 = new Square(0, 0, 4);
    cout << ps2->get_perimeter() << endl;

    RegularPolygon* ps3 = new Square(0, 0, 5);
    cout << ps3->get_perimeter() << endl;

    Shape* ps4 = new Square(0, 0, 6);
    cout << ps4->get_perimeter() << endl;


    delete ps2;
    delete ps3;
    delete ps4;


    // Задача 2:
    // Измените структуру классов, добавив в неё класс Ellipse - Эллипс


    // Протестируйте ваши изменения


    // Задача 3: Вектор из Shape*

    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(0, 0, 5));
    shapes.push_back(new RegularPolygon(1, 1, 4, 10));
    shapes.push_back(new Square(2, 2, 15));

    // Добавьте в вектор shapes несколько эллипсов

    // Напечатайте периметры всех фигур из вектора shapes
    // Используйте range-based for loop


    // Задача 4: Без virtual
    // Что произойдёт, если везде убрать ключевое слово virtual
    // И переопределить метод get_perimeter() класса Shape, так, чтобы он всегда возвращал 777

}