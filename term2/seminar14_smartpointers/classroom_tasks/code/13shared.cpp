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


// Умный указатель shared_ptr вызывает деструктор 
// во время выхода из области видимости последнего указателя,
// ссылающегося на этот объект


int main()
{
    auto p = std::make_shared<Cat>("Alisa");

    if (true)
    {
        std::shared_ptr<Cat> q = p;
    }

    std::shared_ptr<Cat> r  = p;

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
            auto pb = std::make_shared<Cat>("Barsik");
            Cat c {"Casper"};
            std::shared_ptr<Cat> pd = pb;
        }

    Задание 3: Что напечатает следующая программа:
        int main()
        {
            auto p = std::make_shared<Cat>("Alisa");

            if (true)
            {
                auto q = std::make_shared<Cat>("Barsik");
            }

            auto r = std::make_shared<Cat>("Casper");

            std::cout << "End of main\n";
        }
*/
