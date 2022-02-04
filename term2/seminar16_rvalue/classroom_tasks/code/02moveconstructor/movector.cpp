#include <iostream>
#include <string>
using std::cout, std::endl;

// Класс, который наследуется от Animal
class Cat
{
private:
    std::string m_name;
    int m_age;
public:

    Cat() : 
        m_name(""), m_age(0)
    {
        cout << "Default constructor" << endl;
    }

    Cat(std::string name, int age) : 
        m_name(name), m_age(age)
    {
        cout << "Constructor" << endl;
    }

    Cat(const Cat& c) : 
        m_name(c.m_name), m_age(c.m_age)
    {
        cout << "Copy constructor" << endl;
    }


    Cat(Cat&& c) : 
        m_name(std::move(c.m_name)), 
        m_age(std::move(c.m_age))
    {
        cout << "Move constructor" << endl;
    }


    Cat& operator=(const Cat& c)
    {
        cout << "Copy assignment" << endl;
        m_name = c.m_name;
        m_age = c.m_age;
        return *this;
    }


    Cat& operator=(Cat&& c)
    {
        cout << "Move assignment" << endl;
        m_name = std::move(c.m_name);
        m_age = std::move(c.m_age);
        return *this;
    }

    void say() const
    {
        cout << "Meow! My name is " << m_name <<". I am " << m_age << " old." << endl; 
    }

    void incAge()
    {
        m_age++;
    }

    ~Cat()
    {
        cout << "Destructor of Cat" << endl;
    }

};

Cat func(Cat c)
{
    c.incAge();
    return c;
}


int main()
{
    Cat b = func(Cat{"Barsik", 10});
    b.say();


    // b = {"Murka", 2};
    // b.say();
}

