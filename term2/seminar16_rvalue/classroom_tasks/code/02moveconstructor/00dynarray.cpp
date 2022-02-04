#include <iostream>
#include <algorithm>
#include <string>
#include <initializer_list>
#include <cassert>
using std::cout, std::endl;

/*
    Ниже представлена реализация динамического массива из семенира про шаблоны


    Вам нужно дополнить эту реализацию написав:

    1) Конструктор перемещения
        Dynarray(Dynarray&& d)

    2) Оператор присваивания перемещения
        Dynarray& operator=(Dynarray&& d)

    3) Метод pushBack с перемещением входного аргумента
*/



template <typename T>
class Dynarray
{
private:
    T* values;
    size_t capacity;
    size_t size;
    
public:
    Dynarray(size_t initialCapacity) 
    {
        assert(initialCapacity >= 0);
        size = 0;
        capacity = initialCapacity;
        values = new T[capacity];
    }

    Dynarray() : Dynarray(0)
    {
    }

    Dynarray(std::initializer_list<T> il)
    {
        cout << "initializer_list Constructor" << endl;

        size = il.size();
        capacity = size;
        values = new T[capacity];
        std::copy(il.begin(), il.end(), values);
    }

    // Конструктор копирования (глубокая копия)
    Dynarray(const Dynarray& d)
    {
        cout << "Copy Constructor" << endl;

        capacity = d.capacity;
        size = d.size;

        values = new T[capacity];
        for (size_t i = 0; i < size; i++)
            values[i] = d.values[i];
    }


    // Присваивание копированием
    Dynarray& operator=(const Dynarray& d)
    {
        cout << "Copy Assignment" << endl;
        // Проверяем на случай a = a
        if (&d == this)
            return *this;

        delete [] values;
        size = d.size;
        capacity = d.capacity;
        values = new T[capacity];
        for (size_t i = 0; i < size; i++)
            values[i] = d.values[i];
        return *this;
    }

    void pushBack(const T& x) 
    {
        cout << "Copy pushBack" << endl;
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

    T& operator[](size_t id) const
    {
        return values[id];
    }

    size_t getSize() const
    {
        return size;
    }

    ~Dynarray() 
    {
        delete[] values;
    }
};


// Функция, которая добавляет ! к каждой строке динимического массива
// Нужна чтобы можно было получить rvalue выражение типа Dynarray
Dynarray<std::string> addExclamations(Dynarray<std::string> d)
{
    for (int i = 0; i < d.getSize(); ++i)
        d[i] += "!";
    return d;
}



int main()
{
    Dynarray<std::string> a {"Cat", "Dog", "Nutria"};
    Dynarray<std::string> b {"Echidna", "Turtle", "Coati"};


    // Copy constructor
    Dynarray c = a;

    // Move constructor
    Dynarray d = addExclamations(a);


    // Copy assignment
    c = b;
    // Move assignment
    d = {"Mercury", "Venus", "Earth", "Mars"};


    std::string s = "Elephant";

    // Copy pushBack
    c.pushBack(s);

    // Move pushBack
    c.pushBack(std::string("Mouse"));

}
