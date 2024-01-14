/*
    Шаблонный класс массива с фиксированным размером.

    Массивы из языка C имеют множество недостатков.
    Давайте напишем свой массив, с которым было бы удобнее работать.
*/

#include <iostream>
#include <string>
#include <cstdlib>
using std::cout, std::endl, std::size_t;


template <typename T, size_t Size>
class Array 
{
private:
    T data[Size];

public:
    T& operator[](size_t id) 
    {
        return data[id];
    }
};

template <typename T, size_t Size>
std::ostream& operator<<(std::ostream& out, Array<T, Size> array) 
{
    out << "[";
    for (size_t i = 0; i < Size - 1; ++i)
        out << array[i] << ", ";
    
    if (Size != 0)
        out << array[Size - 1];

    out << "]"; 
    return out;
}


int main() 
{
    Array<int, 10> a;
    for (int i = 0; i < 10; ++i)
    {
        a[i] = rand() % 100;
    }
    cout << a << endl;


    Array<std::string, 5> b;
    b[0] = "Cat";
    b[1] = "Dog";
    b[2] = "Zebra";
    b[3] = "Elephant";
    b[4] = "Whale";
    cout << b << endl;


    Array<Array<int, 5>, 5> matrix;
    for (int i = 0; i < 5; ++i) 
    {
        for (int j = 0; j < 5; ++j) 
            matrix[i][j] = rand() % 4;
    }
    cout << matrix << endl;
}




/*
    Задачи:

        1)  Напишите метод at, который будет работать почти как метод operator[], но более безопасно.
            А именно он должен проверять, не вышел ли индекс за границы массива.
            Если мы выходим за границы массива он должен делать одно из следующего (на ваш выбор):

                a)  Печатать сообщение об ошибке и выходить с помощью std::exit(1);

                b)  Кидать исключение:      throw std::out_of_range;


        2)  Добавьте метод reverse, который будет обращать массив. 
            Первый элементы должен поменяться местами с последним, второй - с предпоследним и т. д.

        3)  Добавьте метод sort, который будет сортировать статический массив Array.
            Для простоты используйте сортировку выбором.
            Вот алгоритм сортировки выбором массива a размера n:

                for (size_t j = 0; j < n; ++j)
                {
                    size_t min_index = j;
                    for (size_t i = j + 1; i < n; ++i)
                    {
                        if (a[i] < a[min_index])
                            min_index = i;
                    }

                    T temp = a[j];
                    a[j] = a[min_index];
                    a[min_index] = temp;
                }

            Можно ли отсортировать этим методом массивы Array, содержащий другие массивы Array?

        4)  Перегрузите операторы больше и меньше для этого массива Array (сравнение в лексиграфическом порядке).
            Теперь можно будет отсортировать массивы Array, содержащий другие массивы Array.
        

        5)  Создайте массив пар Array<std::pair<std::string, int>, 5> , заполните его значениями:

                "Cat", 7
                "Cat", 5
                "Dog", 2
                "Ant", 1
                "Cat", 4

            Отсортируйте этот массив и напечатайте его на экран.
            Обратите внимание, что у pair нет перегруженного оператора << с std::ostream.
*/