/*
    Умный указатель можно создать передав адрес созданного объекта в куче. Вот так:

        std::unique_ptr<Cat> p1 {new Cat("Alisa")};
    
    В этом нет ошибки, но использование new обычно считается небезопасным. Например, если вы напишите так:

        Cat* q = new Cat("Alisa");
        std::unique_ptr<Cat> p1 {q};
        std::unique_ptr<Cat> p2 {q};
    
    то это приведёт к ошибке - указатели p1 и p2 будут указывать на один и тот же объект и, в результате,
    этот объект будет освобождён дважды.


    Поэтому лучше использовать специальную функцию std::make_unique, которая будет сама выделять память в куче и 
    создавать объект. Обратите внимание, что в эту функцию передаются аргументы конструктора.
    Функцию std::make_unique удобно использовать вместе с auto.
*/

#include <iostream>
#include <string>
#include <vector>
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




int main()
{
    std::unique_ptr<Cat> p1 {new Cat("Alisa")};

    std::unique_ptr<Cat> p2 = std::make_unique<Cat>("Barsik");

    auto p3 = std::make_unique<Cat>("Casper");


    p1->say();
    p2->say();
    p3->say();
}

/*
    Во всех следующих задачах, решение -- одна строка.
    Для создания указателей используйте функцию std::make_unique и auto.

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