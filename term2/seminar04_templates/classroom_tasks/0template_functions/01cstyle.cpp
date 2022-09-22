/*
    Решение проблемы в языке C

    В языке C данная проблема решается путём написания большого количества функций с разными именами.
    При этом программист, при использовании данных функций должен не ошибиться и выбрать правильную версию.
*/




#include <iostream>

int maxi(int a, int b) 
{
    if (a > b)
        return a;
    else
        return b;
}

long long maxll(long long a, long long b) 
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

float maxf(float a, float b) 
{
    if (a > b)
        return a;
    else
        return b;
}



int main() 
{
    float x = 5.9f;
    float y = 1.7f;

    std::cout << maxf(x, y) << std::endl;
    std::cout << maxi(x, y) << std::endl;
}


/*
    Задача:

        Что напечатает данная функция?
*/
