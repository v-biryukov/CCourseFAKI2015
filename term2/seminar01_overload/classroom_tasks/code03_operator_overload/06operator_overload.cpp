#include <iostream>
using std::cout, std::endl;

struct Complex 
{
    float re, im;
};

Complex operator+(Complex first, Complex second) 
{
    Complex result = {first.re + second.re, first.im + second.im};
    return result;
}

int main() 
{
    Complex z1 = {3, 7};
    Complex z2 = {2, -4};

    Complex z = z1 + z2; 
    cout << z.re << " + " << z.im << "i" << endl;
}

/*
    Задачи:

        1) Перегрузите следующие операторы:
            - Вычитание
            - Умножение
            - Деление
            - Унарный минус
            - Унарный плюс
            - Сравнение ==
            - Сопряжение - это операция, которая меняет знак мнимой части комплексного числа
              Для сопряжения используйте оператор унарная звёздочка *

        2) Перегрузите оператор вывода <<

        3) Напишите функцию exp(z)



    /*
        cout << z1 - z2 << endl;
        cout << z1 * z2 << endl;
        cout << z1 / z2 << endl;
        cout << -z1 << endl;
        cout << *z1 << endl;    // (Комплексно-сопряжённое)

        z = exp(z1 + z2)/(z1 * z2);
        cout << z << endl;
    */
