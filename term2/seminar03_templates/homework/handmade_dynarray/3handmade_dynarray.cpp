#include <iostream>
#include <algorithm>

typedef int Data;

struct Dynarray
{
    size_t size;
    size_t capacity;
    Data* values;


    Dynarray(size_t initialCapacity)
    {
        if (initialCapacity < 0)
        {
            std::cout << "Dynarray's capacity has to be non-negative integer\n";
            exit(1);
        }
        size = 0;
        capacity = initialCapacity;
        values = new Data[capacity];
    }

    Dynarray() : Dynarray(0)
    {
    }

    void pushBack(Data x)
    {
        if (size >= capacity)
        {
            if (capacity == 0)
                capacity = 1;
            else
                capacity *= 2;

            Data* temp = new Data[capacity];
            std::copy_n(values, size, temp);
            delete[] values;
            values = temp;
        }
        values[size] = x;
        size += 1;
    }

    void erase(size_t id)
    {
        if (id < 0 || id >= size)
        {
            std::cout << "Error while erasing element from Dynarray! Index is out of range\n";
            exit(1);
        }
        if (size == 0)
        {
            std::cout << "Error while erasing element from Dynarray! Dynarray is empty\n";
            exit(1);
        }
        for (size_t i = id; i < size - 1; i++)
            values[i] = values[i + 1];
        size--;
    }


    int isEmpty()
    {
        return (size == 0);
    }

    ~Dynarray()
    {
        delete[] values;
    }
};

int main()
{
    Dynarray a;

    for (int i = 0; i < 20; ++i)
    {
        std::cout << "Pushing element " << i * i << ". Size = " << a.size << ". Capacity = " << a.capacity << ".\n";
        a.pushBack(i * i);
    }
    
    std::cout << "Erasing 10th element\n";
    a.erase(10);
    std::cout << "10th element of Dynarray is: " << a.values[10] <<"\n";
}
