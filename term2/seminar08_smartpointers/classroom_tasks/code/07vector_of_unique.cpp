/*
    Предположим мы захотели создать вектор из unique_ptr:
    
        std::vector<std::unique_ptr<int>> v;

    У нас есть умный указатель, который мы хотим добавить в вектор:

        auto p = std::make_unique<int>(100);

    Но добавить в вектор умный указатель p не получится так как для этого нужно копирование, 
    а у unique_ptr удалён конструктор копирования. Следующая строка приведёт к ошибке:
    
        v.push_back(p);


    Но можно использовать конструктор перемещения. В этом случае содержимое p переходит в первый элемент v,
    а сам указатель p становится недействительным:
    
        v.push_back(std::move(p));

    Можно также добавлять временный объект. Так как std::make_unique<int>(200) является rvalue, то автоматически
    вызовется конструктор перемещения
    
        v.push_back(std::make_unique<int>(200));
*/




#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout, std::endl;

class Cat
{
public:

    Cat(std::string name, int age) : mName{name}, mAge{age}
    {
        cout << mName << " Constructor" << endl;
    }

    ~Cat()
    {
        cout << mName << " Destructor" << endl;
    }

    std::string getName()
    {
        return mName;
    }

    int getAge()
    {
        return mAge;
    }

    void say()
    {
        cout << "Meow, I am " << mName << endl;
    }

private:
    std::string mName  {""};
    int mAge           {0};
};



int main()
{
    std::vector<std::unique_ptr<int>> v;

    auto p = std::make_unique<int>(100);

    v.push_back(std::move(p));
    v.push_back(std::make_unique<int>(200));

    for (auto& p : v)
        cout << *p << endl;
}


/*
    Задача:

        Создайте вектор из трёх указателей на объекты Cat
        с именами "Alisa", "Barsik" и "Casper" и возрастами 10, 20 и 30 соответственно
*/
