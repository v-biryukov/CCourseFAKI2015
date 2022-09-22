/*
    В прошлых задачах мы писали шаблонные функции, у которых в качестве шаблона выступал тип элемента вектора. 
    В такую функцию можно было передавать вектора с любыми типами элементов.

    Но что если мы хотим написать функцию, которая работала бы с разными контейнерами (vector, array, string и другие)
    и с любыми типами аргументов.

    Это можно сделать, если в качестве шаблонного аргумента передать сам контейне.
    Тут шаблонный аргумент назван Container, хотя его можно было назвать и T.
*/


#include <iostream>
#include <vector>
#include <string>
#include <array>
using std::cout, std::endl, std::string;



template <typename Container>
typename Container::value_type sum(const Container& c)
{
    using idtype = typename Container::size_type;
    typename Container::value_type result {};

    for (idtype i = 0; i < c.size(); ++i)
    {
        result += c[i];
    }
    return result;
}


int main()
{
    std::array  a {10, 20, 30, 40, 50};
    std::vector v {string("Cat"), string("Dog"), string("Mouse"), string("Lion")};


    cout << sum(a) << endl;
    cout << sum(v) << endl;

}



/*
    Задачи:

        1)  Напишите функцию max, которая принимала бы на вход контейнер и возвращала
            максимальный элемент этого контейнера.
            Эта функция должна работать для контейнеров vector, array с любыми типами элементов,
            а также с контейнером string.

        2)  Напишите функцию reverse, которая принимала бы на вход контейнер и обращала его.
            Эта функция должна работать для контейнеров vector, array с любыми типами элементов,
            а также с контейнером string.

*/