/*
    Умный указатель std::unique_ptr вызывает деструктор во время выхода из области видимости
*/

#include <iostream>
#include <string>
#include <memory>
using std::cout, std::endl;

// Специальный класс, который печатает на экран, когда вызывается его конструктор и деструктор
class Cat
{
private:
    std::string mName {};

public:
    Cat() : mName("None")  {cout << "Cat Default Constructor (" << mName << ")" << endl;}
    Cat(std::string name) : mName(name) {cout << "Cat Constructor (" << mName << ")" << endl;}
    void say() {cout << "Meow, I am " << mName << endl;}
    ~Cat()  {cout << "Cat Destructor (" << mName << ")" << endl;}
};





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
    Задачи:

        1)  Что напечатает эта программа?
            Попробуйте догадаться, прежде чем запустить программу


        2)  В какой последовательности вызовутся деструкторы в следующем участке кода?

                if (true)
                {
                    Cat a {"Alisa"};
                    std::unique_ptr<Cat> pb {new Cat{"Barsik"}};
                    Cat c {"Casper"};
                    std::unique_ptr<Cat> pd {new Cat{"Diana"}};
                }
*/
