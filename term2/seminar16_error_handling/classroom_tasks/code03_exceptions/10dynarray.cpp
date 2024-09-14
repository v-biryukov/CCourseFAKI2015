#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>
#include <initializer_list>
using std::cout, std::endl;


/*
    1) Исправьте данную программу, учитывая то, что оператор new может кидать исключения
    
    2) Исправьте данную программу, учитывая то, что конструктор копирования и оператор
       присваивания может кидать исключения
       
    3) Добавьте конструктор перемещения и оператор присваивания перемещения в класс Dynarray
*/ 




template <typename T>
struct Dynarray
{
private:
    size_t size;
    size_t capacity;
    T* values;

public:
    Dynarray(size_t initial_capacity) 
    {
        assert(initial_capacity >= 0);
        
        size = 0;
        capacity = initial_capacity;
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
        
        size_t i = 0;
        for (const T& x : il)
        {
            values[i] = x;
            i += 1;
        }
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
            for (size_t i = 0; i < size; ++i)
            {
                temp[i] = values[i];
            }
            delete[] values;
            values = temp;
        }
        values[size] = x;
        size += 1;
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
        assert(id >= 0 && id < size);
        return values[id];
    }

    Dynarray& operator=(const Dynarray& right)
    {
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







int main()
{
    Dynarray<std::string> a = {"Cat", "Dog", "Nutria"};
    Dynarray<std::string> b = {"Echidna", "Turtle", "Coati"};

    cout << "a = ";
    for (int i = 0; i < a.getSize(); i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "b = ";
    for (int i = 0; i < b.getSize(); i++)
        cout << b[i] << " ";
    cout << endl;

    a = a;
    b = b;
    b = a;
    cout << "b = a; b = ";
    for (int i = 0; i < b.getSize(); i++)
        cout << b[i] << " ";
    cout << endl;

}
