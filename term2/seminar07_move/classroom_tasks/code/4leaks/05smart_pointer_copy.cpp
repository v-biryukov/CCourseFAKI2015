/*
    Умные указатели. Копирование.


    Обычные указателт мы можем копировать и присваивать, но что произойдёт при копировании нашего умного указателя?
    Так как мы не прописали у него конструктор копирования и оператор присваивания, то они сгенирируются самостоятельно.
    Автоматически сгенерированный конструктор копирования будет просто копировать все поля объекта (в данном случае одно поле)
    Автоматически сгенерированный оператор присваивания будет просто присваивать все поля объекта (в данном случае одно поле)

    Оказывается, что такое копирование и присваивание приводит к ошибкам.

    Задача:

        В данной программе один умный указатель копируется в другой и это приводит к ошибке (неопределённому поведению).
        Из-за чего конкретно происходит эта ошибка?
        Как можно изменить класс SmartPointer, чтобы этой ошибки не возникало?
*/


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