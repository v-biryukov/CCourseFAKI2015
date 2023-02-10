#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout, std::endl;


class Test
{
public:
    Test(int number, int x) : mNumber{number}, mPointer{std::make_unique<int>(x)}
    {
    }

    void print()
    {
        cout << "Number: " << mNumber << endl;
        cout << "Number in Heap " << *mPointer << endl;
    }

private:
    int mNumber                     {0};
    std::unique_ptr<int> mPointer   {nullptr};
};


int main()
{
    Test a {100, 200};
    a.print();
}

/*
    Задача 1:
        Можно ли инициализировать mPointer не в списке инициализации конструктора, а в его теле?

    Задача 2:
        Можно ли скопировать объект типа Test, содержащие unique_ptr? То есть написать так:

            Test b = a;


    Задача 3: Можно ли присвоить объект типа Test другому объекту этого же типа. То есть написать так:

            Test c;
            c = a;


    Задача 4: Создайте новый конструктор  Test(int number, std::unique_ptr<int> p)
            Вызовите этот конструктор из main и протестируйте его работу

*/