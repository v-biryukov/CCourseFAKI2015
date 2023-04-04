/*
    Если функция потока принимает аргумент по ссылке


    Важно понимать, что все аргументы, которые вы передаёте в конструктор std::thread
    будут скопированы или перемещены. Даже если функция принимает этот объект по ссылке.


    Например, в этом примере, функция func принимает объект по ссылке.
    Если мы вызовем эту функцию обычным образом:

        func(a);

    то объект передастся по ссылке и никакого копирования/перемещения происходить не будет.


    Но если мы передадим этот объект на вход конструктору std::thread, то он будет либо
    скопирован либо перемещён в зависимости от категории передаваемого выражения.
*/

#include <thread>
#include <iostream>
using std::cout, std::endl;


// Специальный класс, который печатает на экран, когда вызывается его конструкторы и деструктор
class Cat
{
private:
    std::string mName {};

public:
    Cat() : mName("None")  {cout << "Cat Default Constructor (" << mName << ")" << endl;}
    Cat(std::string name) : mName(name) {cout << "Cat Constructor (" << mName << ")" << endl;}
    Cat(const Cat& c) : mName(c.mName) {cout << "Cat Copy Constructor (" << mName << ")" << endl;}
    Cat(Cat&& c) : mName(std::move(c.mName)) {cout << "Cat Move Constructor (" << mName << ")" << endl;}
    void say() const {cout << "Meow, I am " << mName << endl;}
    ~Cat()  {cout << "Cat Destructor (" << mName << ")" << endl;}
};



void func(const Cat& c)
{
    c.say();
}


int main()
{
    Cat a {"Alice"};
    func(a);


    std::thread t1(func, a);
    t1.join();


    std::thread t2(func, std::move(a));
    t2.join();
}
