/*
    Типы языка C++ поделим на 3 категории:

        1)  Обычные типы (числа, указатели)

        2)  Агрегаты: 
            a)  массивы
            b)  структуры без конструкторов(за исключением тех, что создаются автоматически) и без приватных полей
                                        
        3)  Классы с конструкторами

    
    int, float, double, char int*  - это обычные типы
    Book, int[10], Cat[5]          - это агрегаты
    Cat                            - это класс с конструктором

    Смысл такого разделения в том, что инициализация для разных категорий работает по разному.
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
    void say(){cout << "Meow, I am " << mname << endl;}
};




int main()
{
}

