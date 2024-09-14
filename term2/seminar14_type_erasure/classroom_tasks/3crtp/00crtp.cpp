#include <iostream>
using std::cout, std::endl;

template<typename T>
struct Animal 
{
    void say() 
    { 
        static_cast<T*>(this)->say(); 
    }
};

struct Dog : Animal<Dog> 
{
    void say() 
    { 
        cout << "Dog" << endl; 
    }
};

struct Cat : Animal<Cat> 
{
    void say() 
    { 
        cout << "Cat" << endl; 
    }
};


template<typename T>
void func(Animal<T>& a) 
{
    a.say();
}



int main()
{
    Cat c;
    func(c);
    Dog d;
    func(d);
}