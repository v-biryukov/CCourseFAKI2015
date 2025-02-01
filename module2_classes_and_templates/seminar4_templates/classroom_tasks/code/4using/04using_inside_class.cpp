/*
    Задача

    

    
*/


#include <iostream>
using std::cout, std::endl;


class Cat 
{
public:
    
    using ValueType = std::string;

    Cat(const ValueType value) : mValue{value} {}

    ValueType getValue() const
    {
        return mValue;
    }

private:
    ValueType mValue;
};



class Dog 
{
public:
    
    using ValueType = std::vector<int>;

    Dog(const ValueType value) : mValue{value} {}

    ValueType getValue() const
    {
        return mValue;
    }

private:
    ValueType mValue;
};




int main()
{
    Complex<float> c {1, 2};

    Complex<float>::ValueType x = c.re();
}

