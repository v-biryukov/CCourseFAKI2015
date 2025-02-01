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
    static std::string animalName;
};


int Rectangle::value = 10;

std::string Rectangle::animalName("Cat");


int main()
{
    cout << Rectangle::animalName << endl;
}
