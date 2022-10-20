/*
    В отличии от указателей unique_ptr, указатели shared_ptr можно копировать, присваивать,
    передавать в функцию, используя копирование.
*/


#include <iostream>
#include <string>
#include <vector>
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

    void say() const
    {
        cout << "Meow! My name is " << mName << endl;
    }

    std::string getName() const
    {
        return mName;
    }

private:
    std::string mName {""};
};


void printShared(std::shared_ptr<Cat> p)
{
    cout << "Printng name: " << p->getName() << endl;
    cout << "Count in function = " << p.use_count() << endl;
}


int main()
{
    auto p1 = std::make_shared<Cat>("Alisa");
    auto p2 = p1;

    std::shared_ptr<Cat> p3;
    p3 = p1;

    printShared(p1);

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