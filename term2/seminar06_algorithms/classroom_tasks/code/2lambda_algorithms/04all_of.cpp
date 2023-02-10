/*
    Алгоритмы с компараторами
    
    all_of(it1, it2, f)   -  возвращает true, если все элементы удовлетворяют предикату f, иначе false

    any_of(it1, it2, f)   -  возвращает true, если хотя бы один элемент удовлетворяют предикату f, иначе false

    none_of(it1, it2, f)  -  возвращает true, если ни один из элементов не удовлетворяют предикату f, иначе false
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout, std::endl;

template <typename T>
void printVector(const std::vector<T>& v)
{
    for (typename std::vector<T>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
        cout << *it << " ";
    cout << endl;
}


int main()
{
    std::vector<int> vi {81, 82, 78, 36, 39, 96, 11, 58, 15, 48};
    std::vector<std::string> vs {"Cat", "Dog", "Ocelot", "Camel", "Caterpillar", "Chameleon", "Iguana", "Bat", "Mouse", "Cow"};


    printVector(vi);
    printVector(vs);
}


/*
    Задачи:

        1)  Напишите код, который будет проверять все ли элементы в векторы vi положительные двузначные числа.
            Протестируйте этот код, меняя массив vi.

        2)  Напишите код, который будет проверять все ли элементы в векторе vs начинаются с заглавной буквы.
            Протестируйте этот код, меняя массив vs.


        3)  Напишите функцию containChar, которая будет принимать на вход вектор строк и символ.
            Эта функция должна будет проверять встречается ли этот символ хоть один раз хотя бы в одной из строк.
            Функция должна возвращать true или false соответственно.

                containChar(vs, 'a')  // true
                containChar(vs, 'C')  // true
                containChar(vs, 'A')  // false
                containChar(vs, 'x')  // false
                containChar(vs, 'w')  // true
                
*/