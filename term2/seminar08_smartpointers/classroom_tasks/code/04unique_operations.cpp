/*
    Для умных указателей переопределены операторы унарная звёздочка * и оператор ->
    Они работают по аналогии этими операторами для обычных указателей

    Также, умный указатель может конвертироваться в булевое выражение.
*/

#include <iostream>
#include <string>
#include <memory>

class Cat
{
public:
    Cat(std::string name) : mName{name}
    {
        std::cout << mName << " Constructor" << std::endl;
    }

    ~Cat()
    {
        std::cout << mName << " Destructor" << std::endl;
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


int main()
{
    std::unique_ptr<Cat> p {new Cat("Alisa")};

    (*p).say();
    p->say();

    if (p)
    {
        std::cout << "p equals to true" << std::endl;
    }

    std::unique_ptr<Cat> q {nullptr};
    if (q)
    {
        std::cout << "q equals to true" << std::endl;
    }
}


/*

    Задача:

        Проверьте, есть ли у std::unique_ptr конструктор по умолчанию и, если да, то какой указатель он создаёт.
*/
