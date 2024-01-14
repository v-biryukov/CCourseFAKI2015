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



class Figure
{
private:

    enum class FigureType
    {
        Circle,
        Rectangle
    };

    std::variant<Circle, Rectangle> mValue;
    FigureType mFigureType;


public:

    Figure(Circle c) : mValue(c), mFigureType(FigureType::Circle)
    {
    }

    Figure(Rectangle r) : mValue(r), mFigureType(FigureType::Rectangle)
    {
    }


    void operator=(Circle c)
    {
        mValue = c;
        mFigureType = FigureType::Circle;
    }

    void operator=(Rectangle r)
    {
        mValue = r;
        mFigureType = FigureType::Rectangle;
    }

    void say()
    {
        if (mFigureType == FigureType::Circle)
            std::get<Circle>(mValue).say();

        else if (mFigureType == FigureType::Rectangle)
            std::get<Rectangle>(mValue).say();
    }
};



int main()
{
    Circle c(10);
    Rectangle r(20, 30);


    Figure f(c);

    f.say();

    f = r;

    f.say();



    cout << endl << "Vector of fugures:" << endl;

    std::vector<Figure> v {c, r, Circle{40}, Circle(50), Rectangle{60, 70}, Circle{80}};
    for (auto& el : v)
        el.say();
}
