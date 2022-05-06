#include <iostream>
using std::cout, std::cin, std::endl;


constexpr int square(int a)
{
    return a * a;
}


int main()
{
    constexpr int x = square(9);
    cout << x << endl;
}


/*

    Задание:

        1)  Проверьте как выглядит код ассемблера с использованием constexpr 
            при определении функции и определении переменной

            Проверьте все 4 возможные комбинации

            Для получения кода ассемблера:
            g++ -S -masm=intel 03constexpr_function.cpp

        
        2)  Напишите реккурсивную constexpr функцию, вычисляющую n-е число Фиббоначи
            Проверьте, что она вычисляется во время компиляции, с помощью ассемблирования

*/