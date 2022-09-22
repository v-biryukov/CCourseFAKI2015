/*
    Класс std::pair

    В стандартной библиотеке уже есть класс пары - это класс std::pair из библиотеки utility
*/

#include <iostream>
#include <string>
#include <utility>

using std::cout, std::endl;


int main()
{
    std::pair a {5, std::string("Cat")};
    cout << a.first << " " << a.second << endl;

    cout << std::boolalpha;
    cout << (a > std::pair{5, std::string("Dog")}) << endl;
    cout << (a > std::pair{5, std::string("Ant")}) << endl;
}