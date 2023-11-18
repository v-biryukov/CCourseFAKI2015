/*
    Оператор new и конструкторы

    Зачем нужен новый оператор, если для выделения памяти в куче уже есть функция malloc?

    Оператор new нужен для корректного создания объектов классов в куче.
    Дело в том, что каждый объект класса при своём создании должен вызывать конструктор, а malloc просто выделяет память, 
    а конструктор не вызывает. Поэтому понадобилось ввести новый оператор, который будет выделять необходимую память
    под объект класса а также корректно инициализировать этот объект (то есть вызывать конструктор).



    Для того, чтобы создавать объекты в Куче в C++ следует воспользоваться оператором new:

        type* p = new type;

    Оператор new в этом виде делает следующее:

        1)  Выделяет необходимую память под один объект типа type в Куче
        2)  Инициализирует этот объект, используя default-инициализацию.
            Если type - это класс, то будет вызван его конструктор по умолчанию.



    Для того, чтобы удалить объект, созданный с помощью new, следует использовать оператор delete:
    
        delete p;

    Оператор delete в этом виде делает следующее:
        1)  Вызывает деструктор этого объекта (если у объекта есть деструктор).
        2)  Освобождает память для этого объекта, выделенную с помощью new.
*/

#include <iostream>
#include <cstdlib>
#include <string>
using std::cout, std::endl, std::string;

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
    cout << "Malloc:" << endl;

    Verbose* q = (Verbose*)malloc(sizeof(Verbose));



    cout << "New:" << endl;

    Verbose* p = new Verbose;
}


/*
    Задачи:

        1)  Что напечатает данная программа?

        2)  Используйте функцию free и оператор delete для того, чтобы освободить выделенную память.

        3)  Выделите на куче один объект типа int. Проверьте, будет ли он инициализован нулём.
*/