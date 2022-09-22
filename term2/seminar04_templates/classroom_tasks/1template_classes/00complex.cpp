/*
    Шаблонные классы

    Шаблонными могут быть не только функции, но и классы.
    В данном файле создан шаблонный класс Complex.

    Шаблонные аргументы в некоторых случах можно не писать тогда, когда компилятор может
    догадаться чему они должны быть равны
*/

#include <iostream>

template <typename T>
struct Complex 
{
    T re, im;

    Complex (){};
    Complex (T re0, T im0)      : re(re0),  im(im0)  {}
    Complex (const Complex& c)  : re(c.re), im(c.im) {}

    Complex operator+(Complex c) {return Complex{re + c.re, im + c.im};}
    Complex operator-(Complex c) {return Complex{re - c.re, im - c.im};}
    Complex operator*(Complex c) {return Complex{re * c.re - im * c.im, re * c.im + im * c.re};}

    Complex& operator=(Complex c) 
    {
        re = c.re;
        im = c.im;
        return *this;
    }

    Complex& operator+=(Complex c) 
    {
        re += c.re;
        im += c.im;
        return *this;
    }
};


template <typename T>
void print(Complex<T> c)
{
    std::cout << "(" << c.re << ", " << c.im << ")\n";
}


int main()
{
    Complex<float> a  = {1.5f, -2.1f};
    Complex<double> b = {8.1, 0.1};
    Complex<int> c    = {4, 5};

    print(a);
    print(b);
    print(c);



    Complex x = {1.5f, -2.1f};
    Complex y = {8.1, 0.1};
    Complex z = {4, 5};

    print(x);
    print(y);
    print(z);
}