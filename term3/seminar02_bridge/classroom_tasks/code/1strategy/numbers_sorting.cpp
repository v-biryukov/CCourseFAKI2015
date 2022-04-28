#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using std::cout, std::endl;

/*
    Класс набора чисел, которые можно сортировать
    По умолчанию используется стандартный алгоритм std::sort
*/

class Array
{
private:
    std::vector<int> data;


public:

    Array(std::vector<int> data) : data{data} {}

    void push(int number)
    {
        data.push_back(number);
    }

    void shuffle() 
    {
        size_t n = data.size();
        for(size_t i = 0; i < n; i++)  
        {
            size_t randomIndex = rand() % n;
            std::swap(data[i], data[randomIndex]);
        }
    }

    void sort()
    {
        std::sort(data.begin(), data.end());
    }

    friend std::ostream& operator<<(std::ostream& stream, Array& a);
};


std::ostream& operator<<(std::ostream& stream, Array& a)
{
    for (auto el : a.data)
        stream << el << " ";
    return stream;
}



int main()
{
    Array a {{10, 1, 80, 80, 30, 20, 90}};

    cout << a << endl;
    a.sort();
    cout << a << endl;
    a.shuffle();
    cout << a << endl;
}




/*
    Задача:
        Используйте паттерн Стратегия, чтобы добавить возможность выбирать алгоритм сортировки
        Для этого создайте интерфейс SortAlgorithm и отнаследуйте от него следующие классы:

        BubbleSortAlgorithm
        QuickSortAlgorithm
        BogoSortAlgoritm

        Объекты этих классов должны уметь сортировать набор чисел


        Класс Array должен включать в себя указатель на объект типа SortAlgorithm
        а также метод setSortAlgorithm, который будет задавать необходимый алгоритм сортировки

        Используйте класс Array, чтобы отсортировать набор чисел разными методами


*/




/*

Необходимые алгоритмы сортировки:

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
                std::swap(&arr[j], &arr[j+1]);
        }
    }
}


void quicksort(int array[], int l, int r) 
{
    if (r - l <= 1) 
        return;

    int j = l;
    int pivot = array[r - 1];
    for (int i = l; i < r; i++) 
    {
        if (array[i] <= pivot) 
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            j++;
        }
    }
    quicksort(array, l, j - 1);
    quicksort(array, j, r);
}




bool isSorted(int array[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}

void shuffle(int array[], int n) 
{
    for(int i = 0; i < n; i++)  
    {
        // Каждый элемент меняем местами со случайным
        int randomIndex = rand() % n;

        int temp = array[i];
        array[i] = array[randomIndex];
        array[randomIndex] = temp;
    }
}
 
void bogosort(int array[], int n) 
{
    while (!isSorted(array, n)) 
    {
        shuffle(array, n);
    }   
}

*/