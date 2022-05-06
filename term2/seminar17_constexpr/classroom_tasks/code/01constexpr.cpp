#include <iostream>
using std::cout, std::cin, std::endl;


/*
    Ключевое слово constexpr при объявлении переменной означает, 
    что значение переменной должно быть известно на этапе компиляции

    Инициализировать её можно только значением, известным на этапе компиляции

*/

int main()
{
    int a;
    cin >> a;

    constexpr int b = 123;
    cout << b << endl;
}