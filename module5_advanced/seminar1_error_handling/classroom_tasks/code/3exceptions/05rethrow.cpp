#include <iostream>
#include <exception>
using std::cout, std::endl;


/*
    Исключение можно поймать и бросить заново с помощью оператора
    throw без аргументов
*/


void func()
{
    try
    {
        throw std::runtime_error("My runtime Error");
    }
    catch (std::exception& e)
    {
    	cout << "Caught first time" << endl;
        throw;
    }
}



int main()
{
    try
    {
        func();
    }
    catch (std::exception& e)
    {
    	   cout << "Caught second time" << endl;
        cout << "Error: " << e.what() << endl;
    }
}


/*
    Задания:
        1)  Что напечатает данная программа?
*/
