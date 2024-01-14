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


    std::variant<Circle, Rectangle> f(c);

    std::visit([](auto v){v.say();}, f);

    f = r;

    std::visit([](auto v){v.say();}, f);



    cout << endl << "Vector of fugures:" << endl;

    std::vector<std::variant<Circle, Rectangle>> v {c, r, Circle{40}, Circle(50), Rectangle{60, 70}, Circle{80}};
    for (auto& el : v)
        std::visit([](auto v) {v.say();}, el);
}
