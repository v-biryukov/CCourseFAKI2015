#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;

class Cat
{
private:
    std::string m_name;

public:
    Cat(std::string name) : m_name(name)
    {
        std::cout << m_name << " Constructor" << std::endl;
    }

    ~Cat()
    {
        std::cout << m_name << " Destructor" << std::endl;
    }

    std::string getName()
    {
        return m_name;
    }

    void say()
    {
        std::cout << "Meow" << std::endl;
    }
};


int main()
{
    std::unique_ptr<Cat> p {new Cat("Alisa")};

    // Для умных указателей переопределены операторы
    // унарная звёздочка и оператор ->
    // Они работают по аналогии этими операторами для обычных указателей
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
    Проверьте, есть ли у std::unique_ptr конструктор по умолчанию
    и, если да, то что он создаёт.

*/
