/*
    Решение проблемы с помощью перегрузки функций

    В языке C++ появилась новая возможность - перегрузка функций.
    То есть мы можем создавать функции с одинаковыми названиями, но с разными типами/количеством входных параметров.

    И при вызове функции компилятор посмотрит на типы аргументов и вызовет нужную версию перегруженной функции.
    Нам осталось только написать копию функции для всех вариантов, которые мы когда-либо будем использовать.


    Недостатки перегрузки функций для решения данной проблемы:

    1)  Приходится писать (очень) много кода
    2)  Если нам понадобиться применить функцию getMax к своему классу, то нам придётся писать
        самим ещё одну перегрузку функции getMax для этого класса.
*/

#include <iostream>
#include <string>
using namespace std::string_literals;

int getMax(int a, int b) 
{
    if (a > b)
        return a;
    else
        return b;
}

double getMax(double a, double b) 
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
    std::cout << getMax(5, 10) << std::endl;
    std::cout << getMax(5.9, 1.7) << std::endl;
    std::cout << getMax("Cat"s, "Dog"s) << std::endl;
}