#include <iostream>
#include <algorithm>
#include <string>
#include <initializer_list>

template <typename T>
struct Dynarray
{
private:
    size_t size;
    size_t capacity;
    T* values;

public:
    Dynarray(size_t initialCapacity)
    {
        if (initialCapacity < 0)
        {
            std::cout << "Dynarray's capacity has to be non-negative integer\n";
            exit(1);
        }
        size = 0;
        capacity = initialCapacity;
        values = new T[capacity];
    }

    Dynarray() : Dynarray(0)
    {
    }

    Dynarray(std::initializer_list<T> il)
    {
        size = il.size();
        capacity = size;
        values = new T[capacity];
        std::copy(il.begin(), il.end(), values);
    }

    void pushBack(T x)
    {
        if (size >= capacity)
        {
            if (capacity == 0)
                capacity = 1;
            else
                capacity *= 2;

            T* temp = new T[capacity];
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

    int isEmpty() const
    {
        return (size == 0);
    }

    size_t getSize() const
    {
        return size;
    }

    size_t getCapacity() const
    {
        return capacity;
    }

    T& operator[](size_t id)
    {
        return values[id];
    }

    T& at(size_t id)
    {
        if (id < 0 || id >= size)
        {
            std::cout << "Error! Dynarray id is out of bounds\n";
            std::exit(1);
        }
        return values[id];
    }

    ~Dynarray()
    {
        delete[] values;
    }
};


using std::cout, std::endl;

int main()
{
    // Писать = необязательно
    Dynarray<int> a = {4, 8, 15, 16, 23, 42};
    Dynarray<std::string> b = {"Echidna", "Turtle", "Coati"};

    a[0] = 777;
    b.at(1) = "Axolotl";
    b.pushBack("Hippo");
    
    for (int i = 0; i < a.getSize(); i++)
        cout << a[i] << "\n";

    for (int i = 0; i < b.getSize(); i++)
        cout << b[i] << "\n";

}
