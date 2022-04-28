#include <iostream>
using std::cout;
using std::endl;


class Animal
{
protected:
    std::string name;
    int age;
public:
    Animal() 
    {
        cout << "Default constructor of Animal" << endl;
    };
    Animal(std::string name, int age) : name(name), age(age) 
    {
        cout << "Constructor of Animal" << endl;
    }

    void say()
    {
        cout << "<abstract sound> Name = " << name << " age = " << age << endl;
    }

    void increaseAge()
    {
        age++;
    }
};

// Класс, который наследуется от Animal
class Cat : public Animal
{
private:
    int numberOfMouseCaught;
public:
    // Конструктор Cat вызывает конструктор Animal
    Cat(std::string name, int age, int x) : Animal(name, age), numberOfMouseCaught(x)
    {
        cout << "Constructor of Cat" << endl;
    }

    void say() 
    {
        cout << "Meow! My name is " << name <<". I am " << age << " old. "; 
        cout << "I caught " << numberOfMouseCaught << " mouses!" << endl;
    }

    void mouse_caught()
    {
        numberOfMouseCaught++;
    }
};




int main()
{
    Animal animal("Alisa", 100);
    Cat cat("Casper", 10, 77);

    // static_cast используется для каста вверх по цепи наследования
    Cat* pc = &cat;
    Animal* pa = static_cast<Animal*>(pc);

    pc->say();
    pa->say();


    // Для каста вниз по цепи наследования лучше использовать dynamic_cast:
    Animal* qa = &animal;
    Cat* qc = static_cast<Cat*>(qa);

    qa->say();
    qc->say();


    // Для каста вниз по цепи наследования лучше использовать dynamic_cast:
    Animal* ta = &cat;
    Cat* tc = static_cast<Cat*>(ta);

    ta->say();
    tc->say();
}  
