#include <iostream>
#include <string>
#include <memory>
using std::cout, std::endl;

class Cat
{
public:
    Cat(std::string name) : mName{name}
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

    void say()
    {
    	cout << "Meow" << endl;
    }

private:
    std::string mName;
};



/*
    У std::unique_ptr удалён конструктор копирования, поэтому следующая строка не сработает:
        
        std::unique_ptr<Cat> q1 {p};


    У std::unique_ptr удалён оператор присваивания, поэтому следующие строки не сработает:
    
        std::unique_ptr<Cat> q2;
        q2 = p;
*/
void copyConstructTest()
{
    cout << "\nCopy constructor and assignment operator Test: " << endl;
    std::unique_ptr<Cat> p = std::make_unique<Cat>("Alisa");

    //std::unique_ptr<Cat> q1 {p};

    // std::unique_ptr<Cat> q2;
    // q2 = p;
}



/*
    У std::unique_ptr удалён конструктор копирования, но определён конструктор перемещения
    Конструктор перемещения принимает rvalue-ссылку на объект и 'передаёт' всё содержимое аргумента в наш объект
    При сам объект остаётся в том же месте памяти

    Вызываем конструктор перемещения и передаём всё содержимое объекта q объекту p.

    После строки:

        std::unique_ptr<Cat> q {std::move(p)};

    указатель p больше не владеет объектом. Теперь объектом владеет указатель q.
*/
void moveTest()
{
    cout << "\nMove Test: " << endl;

    std::unique_ptr<Cat> p = std::make_unique<Cat>("Barsik");

    std::unique_ptr<Cat> q {std::move(p)};
    cout << "q points to: " << q->getName() << endl;

    // Строка ниже приведёт к ошибке
    // cout << "p points to: " << p->getName() << endl; 
}



/*
    Метод swap обменивает содержимое указателей p и q.
    То есть то же самое, что и в предыдущем примере.

    После строки:

        std::unique_ptr<Cat> q;
        q.swap(p);

    указатель p больше не владеет объектом. Теперь объектом владеет указатель q.
*/
void swapTest()
{
    cout << "\nSwap Test: " << endl;

    std::unique_ptr<Cat> p {std::make_unique<Cat>("Casper")};

    std::unique_ptr<Cat> q;
    q.swap(p);
    cout << "q points to: " << q->getName() << endl;

    // Строка ниже приведёт к ошибке:
    // cout << "p points to: " << p->getName() << endl; 
}

int main()
{
    copyConstructTest();
    moveTest();
    swapTest();
}
