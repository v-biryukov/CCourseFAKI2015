/*
    Шаблонный using 

    Естественно, новый способ создания новых имён для типов был введён не просто так.
    using имеет дополнительные возможности по сравнению с typedef.
    А именно, можно создавать шаблонный using.

    
    В данном примере создано новое шаблонное имя dog<T> = std::pair<T, T>.
    То есть новое имя dog - это пара с одинаковыми типами первого и второго элемента.
*/


#include <iostream>
#include <string>
using std::cout, std::endl;
using namespace std::string_literals;


template <typename T>
using dog = std::pair<T, T>;


int main()
{
    dog<int> a {10, 20};

    cout << a.first << endl;
    cout << a.second << endl;


    dog<std::string> b {"Alice"s, "Bob"s};

    cout << b.first << endl;
    cout << b.second << endl;
}

/*
    Задача 1:

        Создайте новое имя triplet<T> для типа std::array<T, 3>.
        Создайте объект типа triplet<int> и инициализируйте его числами {10, 20, 30}.


    Задача 2:

        Создайте новое имя info<T, U> для типа std::pair<std::pair<std::string, T>, std::vector<U>>.
        Создайте объект типа info<int, std::string> и инициализируйте его значением:

            {{"Alice", 100}, {"Cat", "Dog", "Mouse", "Elephant"}}

        Создайте объект типа info<std::vector<std::string>, int> и инициализируйте его значением:

            {{"Alice", {"Red", "Blue", "Yellow"}}, {10, 20, 30, 40}}

*/
