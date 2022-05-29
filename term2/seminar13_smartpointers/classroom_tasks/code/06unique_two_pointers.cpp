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
}

/*
    У std::unique_ptr удалён конструктор копирования, но определён конструктор перемещения
    Конструктор перемещения принимает rvalue-ссылку на объект и 'передаёт' всё содержимое аргумента в наш объект
    При сам объект остаётся в том же месте памяти

    Вызываем конструктор перемещения и передаём всё содержимое объекта q объекту p
*/


void moveTest()
{
    cout << "\nMove Test: " << endl;

    std::unique_ptr<Cat> p = std::make_unique<Cat>("Barsik");


    std::unique_ptr<Cat> q {std::move(p)};

    // Теперь указатель q владеет объектом
    cout << "q points to: " << q->getName() << endl;

    // А указатель p не владеет
    // Строка ниже приведёт к ошибке
    // cout << "p points to: " << p->getName() << endl; 
}


void swapTest()
{
    cout << "\nSwap Test: " << endl;

    std::unique_ptr<Cat> p {std::make_unique<Cat>("Casper")};

    // Метод swap обменивает содержимое указателей p и q
    // То есть то же самое, что и в предыдущем примере

    std::unique_ptr<Cat> q;
    q.swap(p);

    // Теперь указатель q владеет объектом
    cout << "q points to: " << q->getName() << endl;

    // А указатель p не владеет
    // Строка ниже приведёт к ошибке
    // cout << "p points to: " << p->getName() << endl; 
}

int main()
{
    copyConstructTest();
    moveTest();
    swapTest();
}
