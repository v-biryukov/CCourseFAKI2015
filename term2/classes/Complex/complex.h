#include <iostream>
#include <cmath>

class Complex         // класс "Комплексное число"
{
private:
    double re, im;      // действительная и мнимая части

public:
    // конструкторы 
    Complex (){};

    Complex (double re0)   
    {
        re = re0;
        im = 0;
    }

    Complex (double re0, double im0)
    {
        re = re0;
        im = im0;
    }

    Complex (const Complex& c)   // конструктор копирования
    {
        re = c.re;
        im = c.im;
    }

    // деструктор
    ~Complex (){}

    // остальные функции

    // Модуль комплексного числа
    double abs ()        
    {
        return sqrt(re * re + im * im);
    }

    // оператор присваивания
    Complex& operator= (const Complex &c)   
    {
        re = c.re;
        im = c.im;
        return (*this);
    }


    // оператор +=
    Complex& operator+= (Complex &c)   
    {
        re += c.re;
        im += c.im;
        return *this;
    }

    // оператор сложения
    Complex operator+ (const Complex &c)   
    {
        return Complex (re + c.re, im + c.im);
    }

    // оператор вычитания
    Complex operator- (const Complex &c)   
    {
        return Complex(re - c.re, im - c.im);
    }

    // оператор умножения
    Complex operator* (const Complex &c)   
    {
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    // оператор деления
    Complex operator / (const Complex &c)   
    {
        Complex temp;

        double norm = c.re * c.re + c.im * c.im;
        temp.re = (re * c.re + im * c.im) / norm;
        temp.im = (im * c.re - re * c.im) / norm;
        return temp;
    }

    // укажем дружественные операторы, которым мы разрешаем доступ
    // к личным (private) данным
    friend std::ostream& operator<< (std::ostream &, const Complex &);   
    friend std::istream& operator>> (std::istream &, Complex &);  


    friend Complex operator+(double first, const Complex& second);
    friend Complex operator*(double first, const Complex& second);      

};

// перегрузка оператора <<
std::ostream& operator<< (std::ostream &out, const Complex &c)
{
    if (c.re != 0)
        out << c.re;

    if (c.im > 0)
    {
        if (c.im != 1.0)
            out << " + " << c.im << "i";
        else
            out << " + i";
    }
    else if (c.im < 0)
    {
        if (c.im != -1.0)
            out << " - " << -c.im << "i";
        else
            out << " - i";
    }
    return out;
}

// перегрузка оператора >>
std::istream& operator>> (std::istream &in, Complex &c)
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