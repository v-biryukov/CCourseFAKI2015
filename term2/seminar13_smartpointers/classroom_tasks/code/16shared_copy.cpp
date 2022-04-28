#include <iostream>
#include <string>
#include <vector>
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
        // cout << m_name << " Constructor" << endl;
    }

    ~Cat()
    {
        // cout << m_name << " Destructor" << endl;
    }

    void say() const
    {
        cout << "Meow! My name is " << m_name << endl;
    }

    std::string getName() const
    {
        return m_name;
    }
};


void printShared(std::shared_ptr<Cat> p)
{
    cout << "Printng name: " << p->getName() << endl;
    cout << "Count in function = " << p.use_count() << endl;
}


int main()
{
    auto p1 = std::make_shared<Cat>("Alisa");

    // В отличии от указателей unique_ptr, указатели shared_ptr можно копировать
    auto p2 = p1;


    // Можно присваивать
    std::shared_ptr<Cat> p3;
    p3 = p1;

    // Можно передавать в функцию, используя копирование
    printShared(p1);


    // Можно вставлять в вектор (без использования перемещения)
    std::vector v {p1, p2, std::make_shared<Cat>("Barsik"), std::make_shared<Cat>("Casper")};
    v.push_back(p3);

    cout << "Printing vector of shared pointers: " << endl;
    for (auto p : v)
        cout << p->getName() << " ";
    cout << endl << endl;


    cout << "Count = " << p1.use_count() << endl;
}


/*
    Задача:
        Что выведет данная программа?
        Попытайтесь понять что она выведет, прежде чем запускать программу

*/