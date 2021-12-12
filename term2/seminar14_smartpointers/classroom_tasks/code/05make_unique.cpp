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
    int m_age;

public:

    Cat(std::string name = "", int age = 0) : m_name(name), m_age(age)
    {
        std::cout << m_name << " Constructor" << std::endl;
    }

    ~Cat()
    {
        std::cout << m_name << " Destructor" << std::endl;
    }

    std::string getName()
    {
        return m_name;
    }

    int getAge()
    {
        return m_age;
    }

    void say()
    {
        std::cout << "Meow, I am " << m_name << std::endl;
    }
};


int main()
{
    // Умный указатель можно создать передав адрес созданного объекта в куче
    std::unique_ptr<Cat> p1 {new Cat("Alisa", 5)};
    // Но использование new всё-равно считается небезопасным

    // Поэтому лучше использовать специальную функцию std::make_unique
    // которая будет сама выделять память в куче и создавать объект
    // Обратите внимание, что в эту функцию передаются аргументы конструктора
    std::unique_ptr<Cat> p2 = std::make_unique<Cat>("Barsik", 10);


    // Эту функцию удобно использовать вместе с auto:
    auto p3 = std::make_unique<Cat>("Casper", 9);


    p1->say();
    p2->say();
    p3->say();
}


/*
    Во всех следующих задачах, решение -- одна строка

    Задача 1:
        Создайте умный указатель на число типа int, равное 123

    Задача 2:
        Создайте умный указатель на объект Cat, вызвав конструктор по умолчанию

    Задача 3:
        Создайте умный указатель на std::string, равное "Hello"

    Задача 4:
        Создайте умный указатель на std::vector, равный {5, 5, 5, 5}

    Задача 5:
        Создайте умный указатель на std::vector, равный {10, 20, 30, 40, 50}

*/