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
    Оптимизация copy elision не всегда работает 
    Например рассмотрим функцию, которая принимает объект и возращает его
*/


Point func0(Point p) 
{
    return p;
}

Point func1(Point p) 
{
    return {p.get_x() + 1, p.get_y() + 1};
}

Point func2(Point p) 
{
    Point q = p;
    q.set_x(q.get_x() + 1);
    q.set_y(q.get_y() + 1);
    return q;
}


int main() 
{
    // Какие конструкторы вызовутся в этом случае:
    func1({6, 2}).print();
    // func0({6, 2}).print();
    // func2({6, 2}).print();

    std::cout << std::endl;
    
    // Какие конструкторы вызовутся в этом случае:
    Point p {6, 2};
    func1(p).print();

    // func0(p).print();
    // func2(p).print();
}