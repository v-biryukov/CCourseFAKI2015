/*
    Для умных указателей переопределены операторы унарная звёздочка * и оператор ->
    Они работают по аналогии с этими операторами для обычных указателей.

    Также, умный указатель может конвертироваться в булевое выражение.
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
    std::unique_ptr<Cat> p {new Cat("Alisa")};

    (*p).say();
    p->say();

    if (p)
    {
        cout << "p equals to true" << endl;
    }

    std::unique_ptr<Cat> q {nullptr};
    if (q)
    {
        cout << "q equals to true" << endl;
    }
}


/*
    Задача:

        Проверьте, есть ли у std::unique_ptr конструктор по умолчанию и, если да, то какой указатель он создаёт.
*/
