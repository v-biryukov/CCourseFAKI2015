/*
    Тестируем объект с удалённым конструктором копирования.
*/

#include <iostream>
#include <string>
#include "complex.h"
using std::cout, std::endl;


struct Number
{
    int data {};

    Number()        : data{0} {};
    Number(int x)   : data{x} {};
    Number& operator =(const Number& right) {data =  right.data; return *this;}
    Number& operator+=(const Number& right) {data += right.data; return *this;}

    Number(const Number& num) = delete;
};

std::ostream& operator<<(std::ostream& out, Number num)
{
    out << num.data;
    return out;
}


template <typename T>
T sum(T arr[], size_t size)
{
    T result {};

    for (size_t i = 0; i < size; ++i)
        result += arr[i];

    return result;
}


int main() 
{
    Number a[5] = {10, 20, 30, 40, 50};
    cout << sum(a, 5) << endl; 
}
