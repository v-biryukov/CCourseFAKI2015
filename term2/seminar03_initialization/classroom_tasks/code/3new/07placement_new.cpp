/*
    Оператор new с размещением (placement new)

    Обычный оператор new делает 2 вещи:
        
        1)  Выделяет память, необходимую для объекта
        2)  Создаёт объект в этой памяти (Если у объекта есть конструктор, то вызывает его)

    Оператор placement new НЕ выделяет память, а только создаёт объект в уже выделенной памяти.
    То есть placement new делает только второй шаг.
    У placement new нет аналога delete, поэтому деструктор придётся вызывать вручную.

    Рассмотри код этого примера:

        1)  void* p = malloc(sizeof(Cat));  -  выделяем память в Куче нужного размера
        2)  Cat* q = new(p) Cat;            -  создаём объект в памяти с помощью placement new

        3)  q->say();                       -  можем работать с объектом через указатель

        4)  q->~Cat();                      -  вызываем деструктор объекта
        5)  free(p);                        -  освобождаем память
        
*/



#include <iostream>
#include <cstdlib>
#include <string>
using std::cout, std::endl, std::string;

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
    void* p = malloc(sizeof(Cat));

    Cat* q = new(p) Cat;

    q->say();

    q->~Cat();

    free(p);
}




/*
    Задачи:

        1)  Создайте объект Cat с помощью placement new на Куче с помощью аргументов конструктора {"Alice", 10}.

        2)  Создайте объект Cat с помощью placement new на Стеке с аргументами конструктора {"Bob", 20}.
*/