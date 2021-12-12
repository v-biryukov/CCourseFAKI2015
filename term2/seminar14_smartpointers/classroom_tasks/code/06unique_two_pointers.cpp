#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;

class Cat
{
private:
    std::string m_name;

public:
    Cat(std::string name) : m_name(name)
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

    void say()
    {
    	std::cout << "Meow" << std::endl;
    }
};


void copyConstructTest()
{
    cout << "\nCopy constructor and assignment operator Test: " << endl;

    std::unique_ptr<Cat> p = std::make_unique<Cat>("Alisa");

    // У std::unique_ptr удалён конструктор копирования
    // Поэтому следующая строка не сработает:
    // std::unique_ptr<Cat> q1 {p};

    // У std::unique_ptr удалён оператор присваивания
    // Поэтому следующие строки не сработает:
    // std::unique_ptr<Cat> q2;
    // q2 = p;
}


// В этом примере используется move-семантика
// Подробно мы будем проходить эту тему позже
void moveTest()
{
    cout << "\nMove Test: " << endl;

    std::unique_ptr<Cat> p = std::make_unique<Cat>("Barsik");

    // У std::unique_ptr удалён конструктор перемещения, но определён конструктор перемещения
    // Конструктор перемещения принимает rvalue-ссылку на объект и
    // 'передаёт' всё содержимое аргумента в наш объект
    // При сам объект остаётся в том же месте памяти
    // std::move - специальная функция, которая приводит аргумент к rvalue-ссылке

    // Вызываем конструктор перемещения и передаём всё содержимое объекта q объекту p
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
