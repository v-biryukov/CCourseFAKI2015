#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout;
using std::endl;

class Cat
{
private:
    std::string m_name;
    int m_age;

public:

    Cat(std::string name = "", int age = 0) : m_name(name), m_age(age)
    {
        std::cout << m_name << " Constructor" << std::endl;
    }

    ~Cat()
    {
        std::cout << m_name << " Destructor" << std::endl;
    }

    std::string getName()
    {
        return m_name;
    }

    int getAge()
    {
        return m_age;
    }

    void say()
    {
        std::cout << "Meow, I am " << m_name << std::endl;
    }
};



int main()
{
    // Предположим мы захотели создать вектор из unique_ptr:
    std::vector<std::unique_ptr<int>> v;


    auto p = std::make_unique<int>(100);
    // Но добавить в вектор умный указатель p не получится так как для этого 
    // нужно копирование, а у unique_ptr удалён конструктор копирования
    // Следующая строка приведёт к ошибке:
    // v.push_back(p);


    // Но можно использовать конструктор перемещения
    // В этом случае содержимое p переходит в первый элемент v
    // А сам указатель p становится недействительным
    v.push_back(std::move(p));

    // Можно также добавлять временный объект
    // Так как std::make_unique<int>(200) является rvalue, то вызовется
    // конструктор перемещения
    v.push_back(std::make_unique<int>(200));


    for (auto& p : v)
        cout << *p << endl;
}


/*
    Задача:
        Создайте вектор из трёх указателей на объекты Cat
        с именами "Alisa", "Barsik" и "Casper" и возрастами 10, 20 и 30
        соответственно
*/
