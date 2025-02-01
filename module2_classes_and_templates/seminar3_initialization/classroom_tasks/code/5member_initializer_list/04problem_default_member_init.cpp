/*
    Задача:

        Что напечатает эта программа?
        Попробуйте догадаться без запуска программы.
        Проверьте себя, запустив программу.
*/

#include <iostream>
#include <string>
using std::cout, std::endl;


class Cat
{
private:

    std::string mName {"Alice"};
    int mAge          {10};

public:

    Cat(const std::string name, int age)
    {
        print();

        mName = name;
        mAge = age;
    }

    void print() const
    {
        cout << "Name: " << mName << ", age: " << mAge << endl;
    }
};


int main()
{
    Cat b("Bob", 20);
    b.print();
}