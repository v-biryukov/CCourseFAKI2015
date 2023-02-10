#include <iostream>
#include <string>
using std::cout, std::endl;

// Специальный класс, который печатает на экран, когда вызывается его конструктор и деструктор
class Cat
{
private:
    std::string mName {};

public:
    Cat() : mName("None")  {cout << "Cat Default Constructor (" << mName << ")" << endl;}
    Cat(std::string name) : mName(name) {cout << "Cat Constructor (" << mName << ")" << endl;}
    void say() {cout << "Meow, I am " << mName << endl;}
    ~Cat()  {cout << "Cat Destructor (" << mName << ")" << endl;}
};


template <typename T>
class SmartPointer
{
private:
    T* mPointer;

public:
    SmartPointer(T* pointer) : mPointer{pointer}
    {
    }

    T& operator*() const
    {
        return *mPointer;
    }

    T* operator->() const
    {
        return mPointer;
    }

    ~SmartPointer()
    {
        delete mPointer;
    }
};

int main()
{
    SmartPointer<Cat> p = new Cat("Alice");
    p->say();


    SmartPointer<Cat> q = p;
    q->say();
} 


/*
    В этой программе происходит двойное освобождение, один раз вызывается new и два раза delete.
    new вызывается в первой строке и указатель, полученный от new, передаётся на вход конструктору объекта p.
    Потом, в конструкторе объекта q, этот указатель копируется в объект q.
    Таким образом объекты p и q будут хранить одинаковые указатели.

    При завершении функции main объекты p и q вызовут свои деструкторы и попробуют освободить одну и ту же память.


    Что делать в этом случае. Есть несколько вариантов:

        1)  Написать конструктор копирования и оператор присваивания у SmartPointer, так чтобы они копировали не только указатель,
            но и объект, на который он указывает.
            Это не очень хорошее решение так как мы хотим, чтобы указатель (даже умный) был достаточно быстрым, а копирование
            всего объекта при каждом копировании указателя может быть очень неэффективно.


        2)  Запретить копирование и присваивание у класса SmartPointer, но вместо этого сделать так, чтобы объекты
            класса SmartPointer можно было перемещать. Как это можно сделать мы пройдём на следующем семинаре.
            Такой подход реализуется в стандартном умном указателе std::unique_ptr из библиотеки memory.
*/
