#include <iostream>
#include <string>
using std::cout, std::endl;

int a = 100;

int f(int x)
{
    return x;
}

int& g(int& x)
{
    return x;
}

int main()
{
    int b = 200;
}


/*
    Задача: Какие следующие выражения являются lvalue, а какие rvalue?
    Переменные a, b и функции f, g определены выше.

        1)  a                   -   lvalue

        2)  b                   -   lvalue

        3)  a + b               -   rvalue

        4)  f(a)                -   rvalue (выражение f(a) соответствует временному объекту - копии a)

        5)  g(a)                -   lvalue (так как выражение g(a) соответствует объекту a)

        6)  g(b)                -   lvalue (так как выражение g(b) соответствует объекту b)

        7)  g(a) + 1            -   rvalue

        8)  f(g(a))             -   rvalue

        9)  123                 -   rvalue

        10) "Hello"             -   lvalue
                                    Это совсем неочевидно. Связано с тем, что строковые литералы во время компиляции 
                                    преобразуются в глобальные массивы.
                                    То есть, строковой литерал "Hello" преобразуется в глобальный массив типа const char[6].
*/