#include <iostream>
#include <cmath>

class Complex 
{
public:
    double re, im;

    // конструкторы 
    Complex (){};
    Complex (double re)             : re{re},   im{0}    {}
    Complex (double re, double im)  : re{re},   im{im}   {}
    Complex (const Complex& c)      : re(c.re), im(c.im) {}

    // деструктор
    ~Complex (){}

    double abs () const
    {
        return std::sqrt(re * re + im * im);
    }

    Complex& operator=(const Complex& c) 
    {
        re = c.re;
        im = c.im;
        return *this;
    }

    Complex& operator+=(const Complex& c) 
    {
        re += c.re;
        im += c.im;
        return *this;
    }

    Complex operator+(const Complex& c) const
    {
        return {re + c.re, im + c.im};
    }

    Complex operator-(const Complex& c) const
    {
        return {re - c.re, im - c.im};
    }

    Complex operator*(const Complex& c) const
    {
        return {re * c.re - im * c.im, re * c.im + im * c.re};
    }

    Complex operator/(const Complex& c) const
    {
        Complex temp;
        double norm = c.re * c.re + c.im * c.im;
        temp.re = (re * c.re + im * c.im) / norm;
        temp.im = (im * c.re - re * c.im) / norm;
        return temp;
    }


    // Унарный оператор -  То есть если z - комплексное число (x + iy), то -z это  (-x - iy)
    Complex operator-() 
    {
        return {-re, -im};
    }

    // Унарный оператор +  Возвращает само число
    Complex operator+() 
    {
        return *this;
    }

    // Унарный оператор *  То есть если z - комплексное число (x + iy), то *z это (x - iy)
    Complex operator*() 
    {
        Complex result(re, -im);
        return {re, -im};
    }

    // Укажем дружественные операторы, которым мы разрешаем доступ к личным (private) данным
    friend std::ostream& operator<< (std::ostream &, const Complex &);   
    friend std::istream& operator>> (std::istream &, Complex &);  

    // дружественные операторы сложения/умножения обычного числа на комплексное (в таком порядке)
    friend Complex operator+(double first, const Complex& second);
    friend Complex operator*(double first, const Complex& second);
};


std::ostream& operator<<(std::ostream& out, const Complex& c) 
{
    if (c.re != 0)
        out << c.re;

    if (c.im > 0) {
        if (c.im != 1.0)
            out << " + " << c.im << "i";
        else
            out << " + i";
    }
    else if (c.im < 0) {
        if (c.im != -1.0)
            out << " - " << -c.im << "i";
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

Complex operator+(double first, const Complex& second) 
{
    Complex result(second);
    result.re += first;
    return result;
}

Complex operator*(double first, const Complex& second) 
{
    Complex result(second);
    result.re *= first;
    result.im *= first;
    return result;
}