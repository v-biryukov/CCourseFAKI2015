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

private:
    std::string mName;
};

/*
    Умный указатель вызывает деструктор во время выхода из области видимости
    Деструкторы вызываются также как и для объектов на стеке
*/


void f()
{
    std::unique_ptr<Cat> p {new Cat("Barsik")};
}

int main()
{
    if (true)
    {
        std::unique_ptr<Cat> p {new Cat("Alisa")};
    }

    f();

    std::unique_ptr<Cat> q {new Cat("Cleo")};
    cout << "End of main\n";
}



/*
    Задание 1: Что напечатает эта программа?
               Попробуйте догадаться, прежде чем запустить программу


    Задание 2: В какой последовательности вызовутся деструкторы
               в следующем участке кода?

        if (true)
        {
            Cat a {"Alisa"};
            std::unique_ptr<Cat> pb {new Cat{"Barsik"}};
            Cat c {"Casper"};
            std::unique_ptr<Cat> pd {new Cat{"Diana"}};
        }
*/
