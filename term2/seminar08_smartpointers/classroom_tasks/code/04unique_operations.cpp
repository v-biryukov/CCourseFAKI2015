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

    std::string getName()
    {
        return mName;
    }

    void say()
    {
        std::cout << "Meow" << std::endl;
    }

private:
    std::string mName;
};



/*
    Для умных указателей переопределены операторы унарная звёздочка * и оператор ->
    Они работают по аналогии этими операторами для обычных указателей

    Также, умный указатель может конвертироваться в булевое выражение.
*/

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

        Проверьте, есть ли у std::unique_ptr конструктор по умолчанию и, если да, 
        то какой указатель он создаёт.
*/
