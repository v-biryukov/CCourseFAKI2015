/*
    Шаблонный класс массива с фиксированным размером
*/



#include <iostream>
#include <string>
#include <cstdlib>

using std::cout, std::endl;


template <typename T, int Size>
class Array 
{
private:
    T data[Size];

public:
    T& operator[](int id) 
    {
        return data[id];
    }
};

template <typename T, int Size>
std::ostream& operator<<(std::ostream& out, Array<T, Size> array) 
{
    out << "[";
    for (int i = 0; i < Size - 1; ++i)
        out << array[i] << ", ";
    
    if (Size != 0)
        out << array[Size - 1];

    out << "]"; 
    return out;
}


int main() 
{
    // Массив чисел
    Array<int, 10> numbers;
    for (int i = 0; i < 10; ++i)
        numbers[i] = rand() % 100;
    cout << numbers << endl;


    // Массив строк
    Array<std::string, 5> strings;
    strings[0] = "Cat";
    strings[1] = "Dog";
    strings[2] = "Zebra";
    strings[3] = "Elephant";
    strings[4] = "Whale";
    cout << strings << endl;


    // Массив массивов
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


        2)  Добавьте метод reverse, который будет обращать статический массив Array. 

        3)  Добавьте метод sort, который будет сортировать статический массив Array.
            Для простоты используйте сортировку выбором.
            Вот алгоритм сортировки выбором массива a размера n:

                for (int j = 0; j < n; ++j)
                {
                    int min_index = j;
                    for (int i = j + 1; i < n; ++i)
                    {
                        if (a[i] < a[min_index])
                            min_index = i;
                    }

                    int temp = a[j];
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