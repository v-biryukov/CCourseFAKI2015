#include <iostream>
#include <exception>
using std::cout, std::endl;


/*
    После того как исключение брошено, программа последовательно выходит из всех
    функций, вызывая деструкторы всех объектов, созданных на стеке
    
*/

class Cat
{
private:
    std::string name = "Barsik";
    int age = 5;
    
public:
    
    Cat() {cout << "Default Constructor" << endl;}
    ~Cat() {cout << "Destructor" << endl;}
    
    Cat(std::string name, int age) : name{name}, age{age}
    {
        cout << "Constructor" << endl;
    }
};

void func1()
{
    Cat c;
    
    throw std::runtime_error("Hello");
}


void func2()
{
    Cat* p = new Cat{};
    
    throw std::runtime_error("Hello");

    delete p;
}


int main()
{
    try
    {
        func1();
    }
    catch (std::exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
}


/*
    Задания:
        1)  Что напечатает данная программа
        
        2)  Если в try-блоке вызвать func2 вместо func1, то что напечатает данная программа
*/
