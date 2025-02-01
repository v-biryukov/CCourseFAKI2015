/*
    Copy elision (переводится как пропуск копирования)

    Copy elision - это особый вид оптимизаций в языках C и C++. Заключается в том, что в некоторых случаях 
    копирование объекта не происходит там, где оно вроде бы должно было происходить.

    Рассмотрим пример из данного файла. Кажется, что тут происходит следующее:

        -   В функции get создаётся объект x типа Verbose.
            Он должен создасться в памяти, которая соответствует функции get.

        -   Затем этот объет возвращается из функции get. 
            При возврате из функции get он должен копироваться из функции get в функцию main. 
            Объект a функции main должен инициализироваться этой копией.

        -   Вызывается деструктор объекта x функции get.

        -   Вызывается деструктор объекта a функции main.
    
    Соответственно, программа должна напечатать следующее:

        Constructor from std::string (Alice)    -   объект создаётся в функции get
        Copy Constructor (Alice)                -   объект копируется из функции get в функцию main
        Destructor (Alice)                      -   объект из функции get уничтожается
        Destructor (Alice)                      -   объект из функции main уничтожается


    Но на самом деле это НЕ происходит. Вместо этого происходит следующее:

        -   Объект x функции get, сразу создаётся в памяти функции main.
            Это происходит, потому что компилятор знает, что объект x будет возвращаться из функции get.
            Таким образом, если сразу создать объект в памяти функции main, то можно избежать
            копирования объекта из функции get в функцию main и ускорить программу.

        -   Вызывается деструктор объекта a функции main.

    На самом деле, программа напечатает следующее:

        Constructor from std::string (Alice)    -   объект сразу создаётся в памяти функции main
        Destructor (Alice)                      -   объект из функции main уничтожается


    Вид copy elision, когда копирование пропускается при возврате из функции называется
    return value optimization или просто RVO.

    Copy elision это особенная оптимизация, так как в отличии от большинства других оптимизаций
    она не просто ускоряет программу, но ещё и может изменить видимое поведение программы (код
    в конструкторе копирования просто не исполняется). 
    Это может быть плохо, если вы делаете что-то важное помимо копирования в конструкторе копирования.
    Несмотря на это данная оптимизация является обязательной для всех компиляторов, так как позволяет
    очень сильно ускорить программу.
*/

#include <iostream>
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
    Verbose& operator=(const Verbose& v)
    {
        mName = v.mName;
        std::cout << "Copy Assignment Operator (" << mName << ")" << std::endl;
        return *this;
    }
};


Verbose get()
{
    Verbose x{"Alice"s};
    return x;
}


int main()
{
    Verbose a = get();
}
