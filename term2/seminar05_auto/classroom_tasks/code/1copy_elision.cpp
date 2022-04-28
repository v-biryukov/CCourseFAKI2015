#include <iostream>
#include <string>

class Point 
{
private:
    double x, y;
    
public:
    Point() : x{0.0}, y{0.0}
    {
        std::cout << "Default Constructor()" << std::endl;
    }

    Point(double x, double y) : x{x}, y{y} 
    {
        std::cout << "Constructor(x, y)" << std::endl;
    }

    Point(const Point& p) : x{p.x}, y{p.y} 
    {
        std::cout << "Copy Constructor(p)" << std::endl;
    }

    double getX() const { return x; }
    double getY() const { return y; }
    
    void setX(double ax) { x = ax; }
    void setY(double ay) { y = ay; }
    
    void print() const
    {
        std::cout << x << ", " << y << std::endl;
    }
};

/*
    Примеры return value optimization
    Можно было ожидать, что внутри функций будут создаваться временные объекты
    Но на самом деле это всё оптимизируется
*/

Point create1() 
{
   return {5, 1};
}

Point create2() 
{
    return create1();
}

Point create3() 
{
    Point temp = create2();
    return temp;
}


int main() 
{
    Point p = create1();
    p.print();

    // Проверьте, какие конструкторы вызовутся при вызове create1, create2 и create3
}