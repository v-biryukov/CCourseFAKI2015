#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout;
using std::endl;


// Чтобы инициализировать поле типа std::unique_ptr
// можно выделить объект в конструкторе

class Test
{
private:
    int m_number;
    std::unique_ptr<int> m_pointer;

public:
    Test(int number, int x) : m_number(number), m_pointer(std::make_unique<int>(x))
    {
    }

    void print()
    {
        cout << "Number: " << m_number << endl;
        cout << "Number in Heap " << *m_pointer << endl;
    }
};


int main()
{
    Test a {100, 200};
    a.print();
}

/*
    Задача 1:
        Можно ли инициализировать m_pointer не в списке инициализации конструктора,
        а в его теле?

    Задача 2:
        Можно ли скопировать объект типа Test, содержащие unique_ptr?
        То есть написать так:

            Test b = a;


    Задача 3: Можно ли присвоить объект типа Test другому объекту этого же типа
        То есть написать так:

            Test c;
            c = a;


    Задача 4: Создайте новый конструктор  Test(int number, std::unique_ptr<int> p)
            Вызовите этот конструктор из main и протестируйте его работу

*/