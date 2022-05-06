#include <iostream>
using std::cout, std::cin, std::endl;

/*
    Constexpr функция может исполнятся и во время компиляции и во время выполнения
*/


constexpr int square(int a)
{
    return a * a;
}


int main()
{
    constexpr int x = square(5);

    int a;
    cin >> a;
    int b = square(a);


    cout << x << " " << b << endl;
}


/*

    Задание:

        1)  Если переменная x не будет constexpr
            int x = square(5);
            а функция square останется constexpr

            То вычисления будут проходить во время компиляции или во время выполнения?
            Проверьте это с помощью ассемблирования

        2)  Тот же вопрос для
            const int x = square(5);

*/