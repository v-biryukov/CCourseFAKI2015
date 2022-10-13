#include <iostream>
#include <string>
using std::cout, std::endl;

// Класс, который наследуется от Animal
class Cat
{
private:
    std::string mName;
    int mAge;
public:

    Cat() : 
        mName(""), mAge(0)
    {
        cout << "Default constructor" << endl;
    }

    Cat(std::string name, int age) : 
        mName(name), mAge(age)
    {
        cout << "Constructor" << endl;
    }

    Cat(const Cat& c) : 
        mName(c.mName), mAge(c.mAge)
    {
        cout << "Copy constructor" << endl;
    }


    Cat(Cat&& c) : 
        mName(std::move(c.mName)), 
        mAge(std::move(c.mAge))
    {
        cout << "Move constructor" << endl;
    }


    Cat& operator=(const Cat& c)
    {
        cout << "Copy assignment" << endl;
        mName = c.mName;
        mAge = c.mAge;
        return *this;
    }


    Cat& operator=(Cat&& c)
    {
        cout << "Move assignment" << endl;
        mName = std::move(c.mName);
        mAge = std::move(c.mAge);
        return *this;
    }

    void say() const
    {
        cout << "Meow! My name is " << mName <<". I am " << mAge << " old." << endl; 
    }

    void incAge()
    {
        mAge++;
    }

    Cat copy()
    {
        cout << 1 << endl;
        Cat c {*this};
        cout << 2 << endl;
        return c;
    }

    ~Cat()
    {
        cout << "Destructor of Cat" << endl;
    }

};

Cat increase(Cat c)
{
    c.incAge();
    return c;
}



void func(Cat c)
{
    c.say();
}


int main()
{
    Cat b {"Cleo", 5};

    func(b.copy());

    // b = {"Murka", 2};
    // b.say();
}

