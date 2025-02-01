/*
    Умный указатель std::unique_ptr

    В стандартной библиотеке языка C++ уже есть умный указатель, который позволяет решить большое количество
    проблем связанных с динамическим выделением памяти. Это умный указатель std::unique_ptr из библиотеки memory.

    Он называется уникальным, так как гарантирует, что всегда будет указывать на область памяти в одиночку
    (при соблюдении некоторых правил работы с этим указателем).
    Такие указатели нелья копировать и присваивать, но можно перемещать.
*/

#include <iostream>
#include <string>
#include <memory>
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



int main()
{
    std::unique_ptr<Cat> p {new Cat("Alice")};
    p->say();


    // Объекты unique_ptr нельзя копировать, строки ниже приведут к ошибке компиляции
    // std::unique_ptr<Cat> q {p};
    // q->say();


    // Но объекты unique_ptr можно перемещать:
    std::unique_ptr<Cat> q {std::move(p)};
    q->say();
} 