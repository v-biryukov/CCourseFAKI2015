/*
    Предположим, что мы хотим создать шаблонную функцию в которую мы будем передавать разные 
    контейнеры (vector, array, string и другие).

    Внутри функции мы видим только тип T, но как узнать тип элемента, который содержится в контейнере?
    Например, мы хотим объявить переменную с тем же типом, что у элементов вектора.
    Можно воспользоваться тем, что внутри всех контейнеров стандартной библиотеки определены 
    using typedef-ы для разных типов:

        value_type - тип элемента
        size_type  - тип используемый, для индексации

    То есть, если у нас есть T = std::vector<float>, то T::value_type будет float.
    Но объявить переменную вот так:

        T::value_type x;

    мы не можем, так как компилятор не может понять, является ли value_type статическим полем или typedef-ом.
    По умолчанию он считает, что это статическое поле.
    Чтобы указать компилятору, что  T::value_type  это тип, нужно написать ключевое слово typename перед ним:

        typename T::value_type x;

*/


#include <iostream>
#include <vector>
#include <string>
#include <array>
using std::cout, std::endl, std::string;


template <typename T>
void func(T c)
{
    cout << c[0] << endl;

    typename T::value_type x = c[0] + c[1];
    cout << x << endl;
}


int main()
{
    std::array  a {10, 20, 30, 40, 50};
    std::vector v {string("Cat"), string("Dog")};


    func(a);
    func(v);
}

