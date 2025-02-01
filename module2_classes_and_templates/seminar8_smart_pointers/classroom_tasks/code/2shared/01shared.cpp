/*
    Умный указатель std::shared_ptr вызывает деструктор во время выхода из области 
    видимости последнего указателя, ссылающегося на этот объект
*/


#include <iostream>
#include <string>
#include <memory>
using std::cout, std::endl;

class Cat
{
public:
    Cat(std::string name) : mName(name)
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
