/*
    Алгоритмы с компараторами
    
    partition(it1, it2, f)    -   перемещает элементы контейнера так, что элементы, которые удовлетворяют условию f
                                  будут стоять в начале

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

        1)  Переместите элементы вектора vi так, чтобы в начале шли чётные, а потом нечётные элементы.

        2)  Переместите элементы вектора vs так, чтобы в начале шли строки, начинающиеся с символа 'C'.
*/