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
    // Этот код приведёт к утечке, если мы забудем delete
    Cat* p = new Cat("Alice");
    p->say();


    // Этот код использует умный указатель и автоматически освободит память
    SmartPointer<Cat> q = new Cat("Barsik");
    q->say();
} 