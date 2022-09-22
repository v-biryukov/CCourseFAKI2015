/*
    Конструкторы вектора

    
    1)  Конструктор по умолчанию. Создаётся вектора размера 0.

            std::vector v;  или  std::vector v(); или  std::vector v{};


    2)  Конструктор от одного целого числа n. Создаёт вектор из n элементов.
        Каждый элемент инициализируется с помощью value инициализации.

            std::vector v(n);   или  std::vector v{n};


    3)  Конструктор от одного целого числа n и одного значения value типа T.
        Создаёт вектор из n элементов - копий value.


            std::vector v(n, value);   или  std::vector v{n, value};


    4)  Конструктор копирования
    
    5)  Конструктор от специального объекта std::initializer_list.
        Благодаря этому конструктору можно создать вектор от произвольного числа аргументов типа T.
        Работает только с фигурными скобками.


            std::vector v {value1, value2, value3, ...};

        Этот конструктор имеет приоритет над остальными конструкторами кроме конструктора по умолчанию.


*/

#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl, std::vector, std::string;


template <typename T>
void printVector(const std::vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}


int main()
{
    vector<int> v1;
    printVector(v1);


    vector<int> v2(5);
    printVector(v2);


    vector<int> v3(5, 10);
    printVector(v3);


    vector<int> v4(v3);
    printVector(v4);


    vector<int> v5{10, 20, 30, 40, 50};
    printVector(v5);



    vector<int> vt {5, 10};
    printVector(vt);
}


/*
    Задача:

        Какие вектора создадутся в следующих строках:
            
            1)  vector<string> v(3, "Cat");
        
            2)  vector<string> v{3, "Cat"};

            3)  vector<int> v(4);

            4)  vector<int> v{4};

            5)  vector<int> v(4, 2);

            6)  vector<int> v{4, 2};
*/



