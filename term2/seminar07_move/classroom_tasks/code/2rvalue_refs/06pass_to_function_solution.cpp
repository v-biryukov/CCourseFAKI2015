#include <iostream>
#include <string>
using std::cout, std::endl;



void funcCLvref(const std::string& s)
{
    cout << s << endl;
}


int main()
{
    std::string a {"Cat"};
    std::string b {"Dog"};



    // Передача в функцию, принимающую по константную lvalue-ссылку
    // Напоминание, что константная lvalue-ссылка может инициализироваться как lvalue, так и rvalue выражениями.

    funcCLvref(a);              // Передача по ссылке объекта a
    funcCLvref(a + b);          // Передача по ссылке временного объекта a + b
                                // Время жизни объекта a + b будет продлено до завершения функции.
    funcCLvref(std::move(a));   // Передача по ссылке объекта a

}