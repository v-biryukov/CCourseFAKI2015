#include <iostream>
#include <string>
#include <memory>

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
};


// Умный указатель вызывает деструктор во время выхода из области видимости
// Деструкторы вызываются также как и для объектов на стеке


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

    std::cout << "End of main\n";
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
