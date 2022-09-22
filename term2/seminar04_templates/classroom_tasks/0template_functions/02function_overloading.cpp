/*
    Решение проблемы с помощью перегрузки функций

    В языке C++ появила новая возможность - перегрузка функций.
    То есть мы можем создавать функции с одинаковыми названиями, но с разными типами/количеством входных параметров.

    И при вызове функции компилятор посмотрит, какие типы у аргументов и вызовет нужную версию перегруженной функции.
    Нам осталось только написать копию функции для всех вариантов, которые мы когда-либо будем использовать.


    Недостатки перегрузки функций для решения данной проблемы:

    1)  Приходится писать (очень) много кода
    2)  Если нам понадобиться применить функцию getMax к своему классу, то нам придётся писать
        самим ещё одну перегрузку функции getMax для этого класса.
*/




#include <iostream>
#include <string>


int getMax(int a, int b) 
{
    if (a > b)
        return a;
    else
        return b;
}

long long getMax(long long a, long long b) 
{
    if (a > b)
        return a;
    else
        return b;
}


unsigned long long getMax(unsigned long long a, unsigned long long b) 
{
    if (a > b)
        return a;
    else
        return b;
}

float getMax(float a, float b) 
{
    if (a > b)
        return a;
    else
        return b;
}


std::string getMax(std::string a, std::string b) 
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


    std::cout << getMax(x, y) << std::endl;
    std::cout << getMax(5, 10) << std::endl;
    std::cout << getMax("Cat", "Dog") << std::endl;
}


/*
    Задачи:

        1)  Что напечатает данная функция?
*/
