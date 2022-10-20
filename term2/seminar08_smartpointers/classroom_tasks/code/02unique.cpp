/*
    Умный указатель вызывает деструктор во время выхода из области видимости
    Деструкторы вызываются также как и для объектов на стеке
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

private:
    std::string mName;
};


void f()
{
    std::unique_ptr<Cat> p {new Cat("Barsik")};
}

int main()
{
    {
        std::unique_ptr<Cat> p {new Cat("Alisa")};
    }

    f();

    std::unique_ptr<Cat> q {new Cat("Cleo")};
    std::cout << "End of main" << std::endl;
}



/*
    Задача 1: Что напечатает эта программа?
               Попробуйте догадаться, прежде чем запустить программу


    Задача 2: В какой последовательности вызовутся деструкторы
               в следующем участке кода?

        if (true)
        {
            Cat a {"Alisa"};
            std::unique_ptr<Cat> pb {new Cat{"Barsik"}};
            Cat c {"Casper"};
            std::unique_ptr<Cat> pd {new Cat{"Diana"}};
        }
*/
