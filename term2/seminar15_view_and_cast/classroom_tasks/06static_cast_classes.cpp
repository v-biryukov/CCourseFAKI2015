#include <iostream>
using std::cout;
using std::endl;


class Dog
{
public:
    std::string name;
    int age;
    Dog();
    Dog(std::string name, int age);
    void say();
};


class Cat
{
public:
    std::string name;
    int age;

    Cat(){};

    Cat(std::string name, int age) : name(name), age(age)
    {
    }

    Cat(const Dog& d) : name(d.name), age(d.age)
    {
    }

    operator Dog()
    {
    	return Dog(name, age);
    }

    void say()
    {
        cout << "Meow! My name is " << name <<". I am " << age << " old. " << endl;
    }
};



Dog::Dog()
{
}

Dog::Dog(std::string name, int age) : name(name), age(age)
{
}

void Dog::say()
{
    cout << "Woof! My name is " << name <<". I am " << age << " old. " << endl;
}





int main()
{
    Cat c {"Casper", 10};
    Dog d {"Druzhok", 15};


    // Делаем static_cast, используя конструктор Cat(const Dog& d)
    Cat a = static_cast<Cat>(d);

	// Делаем static_cast, используя оператор operator Dog() класса Cat
    Dog b = static_cast<Dog>(c);
}  
