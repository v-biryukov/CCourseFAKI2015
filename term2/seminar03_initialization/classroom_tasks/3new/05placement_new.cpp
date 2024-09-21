/*
    Оператор new с размещением (placement new)

    Обычный оператор new делает 2 вещи:
        
        1)  Выделяет память, необходимую для объекта
        2)  Инициализирует объект в этой памяти (Если у объекта есть конструктор, то вызывает его)

    Оператор placement new НЕ выделяет память, а только создаёт объект в уже выделенной памяти.
    То есть placement new делает только второй шаг.
    У placement new нет аналога delete, поэтому деструктор придётся вызывать вручную.

    Рассмотри код этого примера:

        1)  void* p = malloc(sizeof(Verbose));      -  выделяем память в Куче нужного размера

        2)  Verbose* q = new(p) Verbose;            -  создаём объект в памяти с помощью placement new

        3)  cout << q->getName() << endl;           -  можем работать с объектом через указатель

        4)  q->~Verbose();                          -  вызываем деструктор объекта

        5)  free(p);                                -  освобождаем память
*/



#include <iostream>
#include <cstdlib>
#include <string>
using std::cout, std::endl;
using namespace std::string_literals;

class Verbose
{
private:
    std::string mName {};
public:
    Verbose()   {std::cout << "Default Constructor (" << mName << ")" << std::endl;}
    ~Verbose()  {std::cout << "Destructor (" << mName << ")" << std::endl;}
    Verbose(const std::string& name) : mName(name)    {std::cout << "Constructor from std::string (" << mName << ")" << std::endl;}
    Verbose(const Verbose& v)        : mName(v.mName) {std::cout << "Copy Constructor (" << mName << ")" << std::endl;}
    std::string getName() const {return mName;}
};


int main()
{
    int array[sizeof(Verbose)];

    Verbose* q = new(array) Verbose;

    cout << q->getName() << endl;

    q->~Verbose();
}




/*
    Задача 1:
        
        Выделите память под объект тип Verbose на куче, используя malloc. Инициализируйте этот объект на куче
        значением "Alice"s, используя placement new.

    Задача 2:
        
        Выделите память под объект тип Verbose на стеке (просто создав массив нужного размера).
        Инициализируйте этот объект на куче значением "Bob"s, используя placement new.
*/