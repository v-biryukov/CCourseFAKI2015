/*
    Copy list initialization

    Выглядит вот так:

        type a = {arg1, ...}; 

        Также выполняется при передаче в функцию и может выполняться при возврате из функции:

            func({arg1, ...})          return {arg1, ...}

    Объекты инициализируются также как и для просто copy initialization.
*/

#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

struct Book
{
    string title;
    int pages;
    float price;
};

class Cat
{
private:
    string mname {};
    int mage     {};

public:
    Cat()   {cout << "Cat Default Constructor (" << mname << ")" << endl;}
    ~Cat()  {cout << "Cat Destructor ("          << mname << ")" << endl;}
    Cat(const Cat& c)                : mname(c.mname), mage(c.mage) {cout << "Cat Copy Constructor (" << mname << ")" << endl;}
    Cat(const string& name, int age) : mname(name),    mage(age)    {cout << "Cat Constructor ("      << mname << ")" << endl;}
    void setName(const std::string& name) {mname = name;};
    string getName() {return mname;};
};



Cat getAlice()
{
    return {"Alice", 10};
}


void call(Cat a)
{
    cout << "Meow, I am " << a.getName() << endl;
}

int main()
{
    Cat a = getAlice();

    call({"Bob", 20});
}

/*
    Задача:

        Сколько раз вызывается конструктор/деструктор для Alice?  (copy elision)


*/