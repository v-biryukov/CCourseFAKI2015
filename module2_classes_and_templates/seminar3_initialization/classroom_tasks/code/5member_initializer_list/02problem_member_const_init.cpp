/*
    Задача:

        Мы захотели написать класс Cat, содержащий поле mName типа std::string.
        Но также хочется сделать поле mName константным (имена кошек в нашей программе не будут меняться).
        После того, как мы сделали поле mName константным в программе появились ошибки компиляции.

        Сделайте так, чтобы ошибок не было, но поле mName было константным.
*/

#include <iostream>
#include <string>
using std::cout, std::endl;


class Cat
{
private:

    const std::string mName;

public:

    Cat(const std::string& name)
    {
        mName = name;
    }

    void print() const
    {
        cout << mName << endl;
    }
};


int main()
{
    Cat a("Alice");
    a.print();
}