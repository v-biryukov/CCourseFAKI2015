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
    // Предположим мы захотели создать вектор из unique_ptr:
    std::vector<std::unique_ptr<int>> v;


    auto p = std::make_unique<int>(100);
    // Но обычным образом добавить в вектор умный указатель p не получится так как для этого  нужно копирование, 
    // а у unique_ptr удалён конструктор копирования. Следующая строка приведёт к ошибке:
    // v.push_back(p);


    // Но можно использовать перемещение. В этом случае p перемещается в первый элемент v.
    // После этого указатель p становится нулевым.
    cout << p.get() << endl;
    v.push_back(std::move(p));
    cout << p.get() << endl;



    // Можно также добавлять временный объект
    // Так как std::make_unique<int>(200) является временным, то он будет перемещаться в вектор.
    v.push_back(std::make_unique<int>(200));
    for (auto& p : v)
        cout << *p << endl;
}


/*
    Задача:

        Создайте вектор из трёх указателей на объекты Cat с именами "Alisa", "Barsik" и "Casper
*/
