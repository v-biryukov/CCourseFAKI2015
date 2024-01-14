#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <variant>
#include <functional>
#include <stdexcept>
#include <memory>
using std::cout, std::endl;
using namespace std::string_literals;

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



class Any
{
    struct Base
    {
        virtual ~Base() {}
    };

    template <typename T>
    struct Derived : Base
    {
        Derived(const T& value) : value(value) {}
        Derived(T&& value) : value(std::move(value)) {}

        T value;
    };

    Base* mpObject;

public:

    template <typename T>
    Any(const T& x)
    {
        mpObject = new Derived<T>(x);
    }

    template <typename T>
    Any(T&& x)
    {
        mpObject = new Derived<T>(std::move(x));
    }

    Any(const Any& a) = delete;

    ~Any()
    {
        delete mpObject;
    }

    template <typename T>
    void operator=(const T& x)
    {
        delete mpObject;
        mpObject = new Derived<T>(x);
    }

    template <typename T>
    void operator=(T&& x)
    {
        delete mpObject;
        mpObject = new Derived<T>(std::move(x));
    }

    template <typename T>
    friend T& anyCast(Any& a);
};


template <typename T>
T& anyCast(Any& a)
{
    auto* p = dynamic_cast<Any::Derived<T>*>(a.mpObject);

    if (p == nullptr)
    {
        throw std::runtime_error("Bad any cast");
    }

    return p->value;
}




int main()
{
    Any a = 10;

    cout << anyCast<int>(a) << endl;

    a = 1.5;

    cout << anyCast<double>(a) << endl;

    a = "Cat"s;

    cout << anyCast<std::string>(a) << endl;

    std::vector<int> v {10, 20, 30, 40, 50};
    a = std::move(v);

    cout << anyCast<std::vector<int>>(a)[0] << endl;

    cout << v.size() << endl;
}