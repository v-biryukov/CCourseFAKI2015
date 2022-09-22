#include <iostream>
#include <cmath>

class Complex {
private:
    double re, im;
public:
    // конструкторы 
    Complex (){};

    Complex (double re0) {
        re = re0;
        im = 0;
    }

    Complex (double re0, double im0) {
        re = re0;
        im = im0;
    }

    Complex (const Complex& c) {
        re = c.re;
        im = c.im;
    }

    // деструктор
    ~Complex (){}

    double abs () {
        return sqrt(re * re + im * im);
    }

    Complex& operator=(const Complex &c) {
        re = c.re;
        im = c.im;
        return (*this);
    }

    Complex& operator+=(Complex &c) {
        re += c.re;
        im += c.im;
        return *this;
    }

    Complex operator+(const Complex &c) {
        return Complex (re + c.re, im + c.im);
    }

    Complex operator-(const Complex &c) {
        return Complex(re - c.re, im - c.im);
    }

    Complex operator*(const Complex &c) {
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    Complex operator/(const Complex &c) {
        Complex temp;

        double norm = c.re * c.re + c.im * c.im;
        temp.re = (re * c.re + im * c.im) / norm;
        temp.im = (im * c.re - re * c.im) / norm;
        return temp;
    }


    // Унарный оператор -
    // То есть если z - комплексное число x + iy, то -z = - x - iy
    Complex operator-() {
        Complex result(-re, -im);
        return result;
    }

    // Унарный оператор +
    // Ничего не делает
    Complex operator+() {
        return *this;
    }

    // Унарный оператор *
    // То есть если z - комплексное число x + iy, то *z = x - iy
    Complex operator*() {
        Complex result(re, -im);
        return result;
    }

    // укажем дружественные операторы, которым мы разрешаем доступ
    // к личным (private) данным
    friend std::ostream& operator<< (std::ostream &, const Complex &);   
    friend std::istream& operator>> (std::istream &, Complex &);  

    // дружественные операторы сложения/умножения обычного числа на комплексное
    // (в таком порядке)
    friend Complex operator+(double first, const Complex& second);
    friend Complex operator*(double first, const Complex& second);
};


// перегрузка оператора <<
std::ostream& operator<<(std::ostream &out, const Complex &c) {
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

// перегрузка оператора >>
std::istream& operator>>(std::istream &in, Complex &c) {
    in >> c.re >> c.im;
    return in;
}

// Число + комплексное число (в таком порядке)
Complex operator+(double first, const Complex& second) {
    Complex result(second);
    result.re += first;
    return result;
}

// Число * комплексное число (в таком порядке)
Complex operator*(double first, const Complex& second) {
    Complex result(second);
    result.re *= first;
    result.im *= first;
    return result;
}