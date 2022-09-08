#pragma once
#include <cmath>
#include <iostream>

struct Complex 
{
    float re;
    float im;
};


/*
    Передаём аргументы в перегруженные операторы по константным ссылкам ссылки

    В данном случае можно было передавать по значению (так как Complex имеет малый размер)
    Но в общем случае лучше всегда использовать ссылки, по возможность константные

    
    То есть в данном случае можно писать и так:

        Complex operator+(const Complex& a, const Complex& b) 
        {
            Complex result = {a.re + b.re, a.im + b.im};
            return result;
        }

    и так тоже можно:

        Complex operator+(Complex a, Complex b) 
        {
            Complex result = {a.re + b.re, a.im + b.im};
            return result;
        }

    В данном случае второй вариант даже более предпочтителен, так как размер объекта Complex очень мал
    Но в общем случае
*/



float sqr(const Complex& a) 
{
    return a.re * a.re + a.im * a.im;
}

float abs(const Complex& a) 
{
    return std::sqrt(sqr(a));
}


Complex operator+(const Complex& a, const Complex& b) 
{
    Complex result = {a.re + b.re, a.im + b.im};
    return result;
}

Complex operator-(const Complex& a, const Complex& b) 
{
    Complex result = {a.re - b.re, a.im - b.im};
    return result;
}

Complex operator*(const Complex& a, const Complex& b) 
{
    Complex result = {a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re};
    return result;
}

Complex operator/(const Complex& a, const Complex& b) 
{
    float bSquared = sqr(b);
   
    Complex result;
    result.re = (a.re * b.re + a.im * b.im) / bSquared;
    result.im = (a.im * b.re - a.re * b.im) / bSquared;
    return result;
}

Complex& operator+=(Complex& a, const Complex& b) 
{
    a.re += b.re;
    a.im += b.im;
    return a;
}



Complex operator-(const Complex& a) 
{
    Complex result;
    result.re = -a.re;
    result.im = -a.im;
    return result;
}


Complex operator+(const Complex& a) 
{
    return a;
}



/*
    Унарный оператор *
    То есть если z - комплексное число x + iy, то *z = x - iy
*/

Complex operator*(const Complex& a) 
{
    Complex result;
    result.re =  a.re;
    result.im = -a.im;
    return result;
}


Complex operator+(float a, const Complex& b) 
{
    Complex result = b;
    result.re += a;
    return result;
}

Complex operator+(const Complex& a, float b) 
{
    Complex result = a;
    result.re += b;
    return result;
}


Complex operator-(float a, const Complex& b) 
{
    Complex result = -b;
    result.re += a;
    return result;
}


Complex operator-(const Complex& a, float b) 
{
    Complex result = a;
    result.re -= b;
    return result;
}




Complex operator*(const Complex& a, float b) 
{
    Complex result = a;
    result.re *= b;
    result.im *= b;
    return result;
}

Complex operator*(float a, const Complex& b) {
    return b * a;
}



Complex operator/(const Complex& a, float b) 
{
    Complex result = a;
    result.re /= b;
    result.im /= b;
    return result;
}


Complex operator/(float a, const Complex& b) 
{
    float bSquared = sqr(b);
    return (a * (*b)) / bSquared;
}


/*
    Перегружаем оператор<< между типами std::ostream (такой тип имеет std::cout) и Complex

    Обратите внимание, что мы возвращаем ссылку на ostream
    Таким образом результатом выражения  cout << a  будет cout
    Поэтому можно делать так: cout << a << b << c ...
*/

std::ostream& operator<<(std::ostream& out, const Complex& a) 
{
    if (a.re != 0)
        out << a.re;

    if (a.im > 0)
    {
        if (a.im != 1.0)
            out << " + " << a.im << "i";
        else
            out << " + i";
    }
    else if (a.im < 0) 
    {
        if (a.im != -1.0)
            out << " - " << -a.im << "i";
        else
            out << " - i";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Complex& c) 
{
    in >> c.re >> c.im;
    return in;
}




Complex exp(const Complex& a) 
{
    Complex result;
    result.re = std::exp(a.re) * std::cos(a.im);
    result.im = std::exp(a.re) * std::sin(a.im);
    return result;
}

Complex sin(const Complex& a) 
{
    Complex result;
    result.re = std::sin(a.re) * std::cosh(a.im);
    result.im = std::cos(a.re) * std::sinh(a.im);
    return result;
}

Complex cos(const Complex& a) 
{
    Complex result;
    result.re = std::cos(a.re) * std::cosh(a.im);
    result.im = std::sin(a.re) * std::sinh(a.im);
    return result;
}