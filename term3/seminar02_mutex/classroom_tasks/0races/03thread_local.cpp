/*

*/
#include <thread>
#include <iostream>
#include <chrono>
#include <string>
using namespace std::chrono_literals;
using std::cout, std::endl;



class Cat
{
private:
    std::string mname {};
    int mage     {};

public:
    Cat()   {cout << "Cat Default Constructor (" << mname << ")" << endl;}
    ~Cat()  {cout << "Cat Destructor ("          << mname << ")" << endl;}
    Cat(const std::string& name, int age) : mname(name), mage(age) {cout << "Cat Constructor (" << mname << ")" << endl;}

    void say() {cout << "Meow, I am " << mname << endl;}
};


thread_local Cat a("Alice", 100);


void func()
{
    
    cout << &a << endl;
    a.say();
}



int main()
{
    std::thread t1(func);
    std::thread t2(func);


    t1.join();
    t2.join();
}