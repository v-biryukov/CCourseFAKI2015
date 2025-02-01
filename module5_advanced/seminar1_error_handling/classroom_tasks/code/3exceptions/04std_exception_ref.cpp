#include <iostream>
#include <exception>
using std::cout, std::endl;


/*
    В данном примере мы бросаем объект типа std::runtime_error
    и ловим его по ссылке на std::exception
    
    Это сработает, так как std::runtime_error наследуется от std::exception
*/



int main()
{
    try
    {
        throw std::runtime_error("My runtime Error");
    }
    catch (std::exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
}


/*
    Задания:
        1)  Что напечатает данная программа?
        
        2)  Что будет, если мы будем ловить это исключение не по ссылке, а по значению
        
        		catch (std::exception& e)   -->   catch (std::exception e)
        		
        3)  Создайте свой класс ошибки, который будет наследником класса std::runtime_error
        	  Помимо строки (описания ошибки) этот класс должен в себе хранить адрес (void*)
        	  того объекта в котором произошла ошибка
        	  (предполагается, что эта ошибка будет бросаться только в методах)
        	  Бросьте это исключение и поймайте его
*/
