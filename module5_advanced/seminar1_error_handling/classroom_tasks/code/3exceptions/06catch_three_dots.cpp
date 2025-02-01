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
        throw 123;
        throw std::runtime_error("My runtime Error");
    }
    catch (std::exception& e)
    {
    	   cout << "Caught first time" << endl;
    	   // Делаем важные вещи, которые нужно сделать независимо от исключения
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
    	   cout << "Caught second time (std::exception)" << endl;
        cout << "Error: " << e.what() << endl;
    }
    catch (int x)
    {
    	   cout << "Caught second time (int)" << endl;
        cout << "Error: " << x << endl;
    }
}


/*
    Задания:
        1)  Что напечатает данная программа?
        
        2)  В данном примере мы хотим, чтобы в функции func исключение ловилось
            всегда независимо от типа (даже если это не наследник std::exception)
            
            Для этого можно использовать синтаксис:
            catch(...)
            
            Сделайте так, чтобы в функции func ловилось исключение любого типа.
*/
