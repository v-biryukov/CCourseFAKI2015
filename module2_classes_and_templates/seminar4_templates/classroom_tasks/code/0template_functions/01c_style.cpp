/*
    Решение проблемы в языке C

    В языке C данная проблема решается путём написания большого количества функций с разными именами.
    При этом программист, при использовании данных функций, должен не ошибиться и выбрать правильную версию.
*/

#include <iostream>

int maxi(int a, int b) 
{
    if (a > b)
        return a;
    else
        return b;
}

double maxd(double a, double b) 
{
    if (a > b)
        return a;
    else
        return b;
}

unsigned long long maxull(unsigned long long a, unsigned long long b) 
{
    if (a > b)
        return a;
    else
        return b;
}



int main() 
{
    std::cout << maxd(5.9, 1.7) << std::endl;
    std::cout << maxi(5.9, 1.7) << std::endl;
}


/*
    Задача:

        Что напечатает данная программа?
*/
