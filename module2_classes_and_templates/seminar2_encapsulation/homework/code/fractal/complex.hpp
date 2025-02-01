/*
    Код для работы с комплексными числами.

    Определены структура Complex, представляющее комплексное число, а также некоторые функции для
    работы с такими числами.

    Перегружены бинарные арифметические операторы между.
    Как для двух комплексных чисела, так и для одного комплексного числа и обычного числа.

        + - * /

    Перегружены операторы присваивания сложения и присваивания вычитания.
    Как для двух комплексных чисела, так и для одного комплексного числа и обычного числа.

        += -=

    Перегружены унарные операторы:

        + - *

    Унарный * для комплексных чисел будет означать сопряжение.
    То есть если z - комплексное число x + iy, то *z это x - iy.

    
    Перегружены операторы вывода на экран и считывания с экрана:

        << >>

    Написаны функции:

        exp sin cos


    Простой оператор присваивания(=) нельзя перегрузить, используя обычные функции (можно только через методы).
    Тем не менее, присваивать эти комплексные числа можно, так как Complex это просто структура.
    А любые обычные структуры можно просто присваивать.
    При этом просто копируются побайтово все элементы структуры (а это то что нужно).
*/
#pragma once
#include <cmath>
#include <iostream>

struct Complex 
{
    float re;
    float im;
};

// Арифметические операторы, два комплексных числа

Complex operator+(Complex a, Complex b) 
{
    Complex result = {a.re + b.re, a.im + b.im};
    return result;
}

Complex operator-(Complex a, Complex b) 
{
    Complex result = {a.re - b.re, a.im - b.im};
    return result;
}

Complex operator*(Complex a, Complex b) 
{
    Complex result = {a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re};
    return result;
}

Complex operator/(Complex a, Complex b) 
{
    float bSquared = b.re * b.re + b.im * b.im;
   
    Complex result;
    result.re = (a.re * b.re + a.im * b.im) / bSquared;
    result.im = (a.im * b.re - a.re * b.im) / bSquared;
    return result;
}


// Арифметические операторы, комплексное число и вещественное

Complex operator+(Complex a, float b) 
{
    Complex result = {a.re + b, a.im};
    return result;
}

Complex operator+(float a, Complex b) 
{
    return b + a;
}

Complex operator-(Complex a, float b) 
{
    Complex result = {a.re - b, a.im};
    return result;
}

Complex operator-(float a, Complex b) 
{
    return b - a;
}

Complex operator*(Complex a, float b) 
{
    Complex result = {a.re * b, a.im * b};
    return result;
}

Complex operator*(float a, Complex b) 
{
    return b * a;
}

Complex operator/(Complex a, float b) 
{
    Complex result = {a.re / b, a.im / b};
    return result;
}

Complex operator/(float a, Complex b) 
{
    Complex ac = {a, 0.0f};
    return ac / b;
}


// Операторы присваиваний сложения и т. п.

Complex& operator+=(Complex& a, Complex b) 
{
    a.re += b.re;
    a.im += b.im;
    return a;
}

Complex& operator-=(Complex& a, Complex b) 
{
    a.re -= b.re;
    a.im -= b.im;
    return a;
}


Complex& operator+=(Complex& a, float b) 
{
    a.re += b;
    return a;
}

Complex& operator-=(Complex& a, float b) 
{
    a.re -= b;
    return a;
}

Complex& operator*=(Complex& a, float b) 
{
    a.re *= b;
    a.im *= b;
    return a;
}

Complex& operator/=(Complex& a, float b) 
{
    a.re /= b;
    a.im /= b;
    return a;
}


// Унарные операторы


Complex operator+(Complex a) 
{
    return a;
}

Complex operator-(Complex a) 
{
    Complex result;
    result.re = -a.re;
    result.im = -a.im;
    return result;
}

Complex operator*(Complex a) 
{
    Complex result = {};
    result.re =  a.re;
    result.im = -a.im;
    return result;
}



/*
    Перегружаем оператор<< между типами std::ostream (такой тип имеет std::cout) и Complex
    для удобного вывода комплексных чисел на экран.

    Обратите внимание, что мы возвращаем ссылку на ostream.
    Таким образом результатом выражения  cout << a  будет cout.
    Поэтому можно делать так: cout << a << b << c ...
*/

std::ostream& operator<<(std::ostream& out, Complex a) 
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


// Функции

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