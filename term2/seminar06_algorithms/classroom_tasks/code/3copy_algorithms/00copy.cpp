/*
    Копирование
    
    copy(it1, it2, itOut)           -   копирует диапазон [it1, it2) в место, задаваемое итератором itOut

    copy_if(it1, it2, itOut, f)     -   копирует только те элементы, которые удовлетворяют условию f

    !!  Если там, где мы записываем, не хватит места, то будет выход за границы контейнера, это неопределённое поведение.
        Поэтому с этой функцией нужно соблюдать осторожность.

*/

#include <iostream>
#include <vector>
#include <string>
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
    std::vector<int> v1 {81, 82, 78, 36, 39, 96, 11, 58, 15, 48};
    printVector(v1);
    
    std::vector<int> v2(v1.size());
    std::copy(v1.begin(), v1.end(), v2.begin());
    printVector(v2);


    int numberOfEven = std::count_if(v1.begin(), v1.end(), [](int a) {return a % 2 == 0;});
    std::vector<int> v3(numberOfEven);
    std::copy_if(v1.begin(), v1.end(), v3.begin(), [](int a) {return a % 2 == 0;});
    printVector(v3);
}


/*
    Задачи:

        Пусть есть такой вектор строк:

            std::vector<std::string> vs {"Cat", "Dog", "Ocelot", "Camel", "Caterpillar", "Chameleon", "Iguana", "Bat", "Mouse", "Cow"};

        Создайте новый вектор строк, и скопируйте в него все строки, начинающиеся на символ 'C'.  
*/