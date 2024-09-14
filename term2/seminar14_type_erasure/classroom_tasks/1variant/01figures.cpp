#include <iostream>
#include <vector>
#include <variant>
using std::cout, std::endl;


class Circle
{
private:
    float mRadius;

public:
    Circle(float radius) : mRadius(radius) {}

    void say()
    {
        cout << "Circle, radius = " << mRadius << endl;
    }
};


class Rectangle
{
private:
    float mWidth;
    float mHeight;

public:
    Rectangle(float width, float height) : mWidth(width), mHeight(height) {}

    void say()
    {
        cout << "Rectangle, width = " << mWidth << ", height = " << mHeight << endl;
    }
};



int main()
{
    Circle c(10);
    Rectangle r(20, 30);


    std::variant<Circle, Rectangle> figure = c;

    std::get<Circle>(figure).say();

    figure = r;

    std::get<Rectangle>(figure).say();
}
