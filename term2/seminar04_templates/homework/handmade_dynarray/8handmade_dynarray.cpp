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
    typedef T* iterator;

    iterator begin()
    {
        return &values[0];
    }

    iterator end()
    {
        return &values[size];
    }

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

    Dynarray& operator=(const Dynarray& right)
    {
        // Проверяем на случай a = a
        if (&right == this)
            return *this;

        delete[] values;
        size = right.size;
        capacity = right.capacity;
        values = new T[capacity];
        for (size_t i = 0; i < size; i++)
            values[i] = right.values[i];
        return *this;
    }

    ~Dynarray() 
    {
        delete[] values;
    }
};


using std::cout, std::endl, std::string;

int main()
{
    Dynarray<string> a = {"Cat", "Dog", "Nutria", "Echidna", "Turtle", "Coati"};

    // Теперь можно использовать удобный цикл
    // Благодаря тому, что у класса есть методы begin() и end(),
    // которые возвращают объект с операциями +-число и унарный *
    // В данном случае это просто указатель, но в случаи других структур данных это может быть болуу сложный итератор

    for (string& s : a)
        s = "(" + s + ")";

    for (const string& s : a)
        cout << s << endl;
}
