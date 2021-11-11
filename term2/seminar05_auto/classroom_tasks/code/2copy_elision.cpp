#include <iostream>
#include <string>

class Point {
private:
    double x, y;
    
public:
    Point() : x(0), y(0) {
        std::cout << "Default Constructor()" << std::endl;
    }
    Point(double x, double y) : x(x), y(y) {
        std::cout << "Constructor(" << x << ", " << y << ")" << std::endl;
    }
    Point(const Point& p) : x(p.x), y(p.y) {
        std::cout << "Copy Constructor(p)" << std::endl;
    }
    double get_x() const {
        return x;
    }
    double get_y() const {
        return y;
    }

    void set_x(double ax) {
        x = ax;
    }
    void set_y(double ay) {
        y = ay;
    }
    
    void print() const {
        std::cout << x << ", " << y << std::endl;
    }
};

/*
    Примеры copy elision
    Можно было ожидать, что при передаче в функцию будут создаваться временные объекты
    Но на самом деле это всё оптимизируется
*/


void take(Point p) {
   std::cout << "take : x = " << p.get_x() << ", " << p.get_y() << std::endl;
}



int main() {
    take({1, 2});
    // take(Point(3, 4));
    // take(Point{5, 6});

    // Сравните с этим:
    // std::cout << std::endl;
    // Point p {7, 8};
    // take(p);
}