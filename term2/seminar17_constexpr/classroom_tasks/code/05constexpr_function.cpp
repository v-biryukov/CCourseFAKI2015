#include <iostream>
using std::cout, std::cin, std::endl;


constexpr int func(int a)
{
    constexpr int b = 2 * a;
    return b;
}


int main()
{
    constexpr int x = func(5);
    cout << x << endl;
}


/*

    Задание:

        1)  Какой будет результат выполнения этой программы?
            Как сделать так, чтобы программа работала как надо

*/