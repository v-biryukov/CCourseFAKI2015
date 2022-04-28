#include <iostream>
#include <cmath>
using std::cout, std::endl;

/*
    Скрытый указатель this
    В методах каждого класса можно использовать скрытый указатель this
    Это просто указатель на данный экземпляр
*/


struct Point 
{
private:
    float x, y;

public:

    Point(float x, float y) 
    {
        this->x = x;
        this->y = y;
    }

    Point() 
    {
        x = 0;
        y = 0;
    }

    void printThis() const 
    {
        cout << this << endl;
    }

    float getX() const
    {
        return x;
    }

    float getY() const 
    {
        return y;
    }


    Point operator+(const Point& right) const 
    {
        Point result = Point(x + right.x, y + right.y);
        return result;
    }
};


ostream& operator<<(ostream& left, Point& right) 
{
    left << "(" << right.getX() << ", " << right.getY() << ")";
    return left;
}

int main() {
    Point a = Point(7, 3);

    a.printThis();
    cout << &a << endl;
}


/* 
    Задание:
    
    1) Запустите эту программу, чтобы проверить, что this это действительно &a

    2) Напишите оператор присваивания:
        Point& operator=(const Point& right)
       Помните, что такой оператор должен вернуть ссылку на экземпляр
       Решение этой  задачи -- в следующей части
*/