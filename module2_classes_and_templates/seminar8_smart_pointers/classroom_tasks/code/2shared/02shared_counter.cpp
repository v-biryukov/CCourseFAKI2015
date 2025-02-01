/* 
    Откуда shared_ptr знает когда ему вызвать конструктор?
    Просто каждый объект типа shared_ptr помимо самого указателя хранит указатель на целое число - счётчик.
    Все shared_ptr, указывающие на один объект, указывают и на один счётчик.

    Упрощённо приватные поля shared_ptr могут выглядеть так:

    template <typename T>
    class shared_ptr
    {
        T* m_data;
        int* m_counter;
        ...
    };

    Конструктор shared_ptr(T*) выделяет память под счётчик и задаёт его единицей.

    Конструктор копирования shared_ptr(const T& p) устанаваливает значение
    m_counter таким же, как и у копируемого указателя, и увеличивает его на 1.

    Узнать значение *m_counter можно с помощью метода use_count.
*/

#include <iostream>
#include <string>
#include <memory>

using std::cout, std::endl;

class Cat
{
public:
    Cat(std::string name) : mName{name}
    {
        cout << mName << " Constructor" << endl;
    }

    ~Cat()
    {
        cout << mName << " Destructor" << endl;
    }

private:
    std::string mName;
};



int main()
{
    auto p1 = std::make_shared<Cat>("Alisa");
    auto p2 = p1;

    cout << "Count = " << p1.use_count() << endl;

    if (true)
    {
        auto p3 = p1;
        cout << "Count = " << p1.use_count() << endl;
    }

    auto p4 = p2;
    cout << "Count = " << p1.use_count() << endl;

    std::cout << "End of main\n";
}


/*
    Задание 1: 

        Что напечатает эта программа?
        Попробуйте догадаться, прежде чем запустить программу.
*/
