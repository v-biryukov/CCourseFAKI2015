#pragma once
#include <cmath>
#include <iostream>

struct Complex
{
    float re;
    float im;
};


// Передаёмм аргументы через ссылки
// В данном случае можно было передавать по значению 
// (так как Complex имеет малый размер)
// Но в общем случае лучше для структур лучше
// всегда использовать ссылки 

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
    float b_squared = b.re * b.re + b.im * b.im;
   
    Complex result;
    result.re = (a.re * b.re + a.im * b.im) / b_squared;
    result.im = (a.im * b.re - a.re * b.im) / b_squared;
    return result;
}

Complex& operator+=(Complex &a, const Complex &b)   
{
    a.re += b.re;
    a.im += b.im;
    return a;
}


// Унарный оператор -
// То есть если z - комплексное число x + iy, то -z = - x - iy
Complex operator-(const Complex& a)
{
    Complex result;
    result.re = -a.re;
    result.im = -a.im;
    return result;
}

// Унарный оператор +
// Ничего не меняет
Complex operator+(const Complex& a)
{
    Complex result = a;
    return result;
}

// Унарный оператор *
// То есть если z - комплексное число x + iy, то *z = x - iy
// Оператор сопряжения
Complex operator*(const Complex& a)
{
    Complex result;
    result.re =  a.re;
    result.im = -a.im;
    return result;
}


// Число + комплексное число (в таком порядке)
Complex operator+(float a, const Complex& b)
{
    Complex result = b;
    result.re += a;
    return result;
}

// Комплексное число + число
Complex operator+(const Complex& a, float b)
{
    Complex result = a;
    result.re += b;
    return result;
}

// Число - комплексное число (в таком порядке)
Complex operator-(float a, const Complex& b)
{
    Complex result = -b;
    result.re += a;
    return result;
}

// Комплексное число - число
Complex operator-(const Complex& a, float b)
{
    Complex result = a;
    result.re -= b;
    return result;
}



// Комплексное число * число
Complex operator*(const Complex& a, float b)
{
    Complex result = a;
    result.re *= b;
    result.im *= b;
    return result;
}

// Число * комплексное число
Complex operator*(float a, const Complex& b)
{
    Complex result = b;
    result.re *= a;
    result.im *= a;
    return result;
}


// Комплексное число / число
Complex operator/(const Complex& a, float b)
{
    Complex result = a;
    result.re /= b;
    result.im /= b;
    return result;
}

// Число / комплексное число
Complex operator/(float a, const Complex& b)
{
    float b_squared = b.re * b.re + b.im * b.im;
    return (a * (*b)) / b_squared;
}


// Перегружаем оператор<< между типами 
// std::ostream (такой тип имеет std::cout) и Complex
// Обратите внимание, что мы возвращаем ссылку на ostream
// Таким образом результатом выражения  cout << a  будет cout
// Поэтому можно делать так: cout << a << b << c ...
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

float abs(const Complex& a)        
{
    return sqrtf(a.re * a.re + a.im * a.im);
}

Complex exp(const Complex& a)        
{
    Complex result;
    result.re = expf(a.re) * cosf(a.im);
    result.im = expf(a.re) * sinf(a.im);
    return result;
}

Complex sin(const Complex& a)        
{
    Complex result;
    result.re = sinf(a.re) * coshf(a.im);
    result.im = cosf(a.re) * sinhf(a.im);
    return result;
}

Complex cos(const Complex& a)        
{
    Complex result;
    result.re = cosf(a.re) * coshf(a.im);
    result.im = sinf(a.re) * sinhf(a.im);
    return result;
}