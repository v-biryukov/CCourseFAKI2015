#include <iostream>
using std::cout, std::endl;


/*
    Оператор throw последовательно выходит из всех функций пока не достигнет блока try-catch

    В блоке try пишется код, который может выбросить исключения.
    После catch указывается тип выброшенного аргумента.
    Если тип совпадает, то программа выполняет блок catch и продолжает выполнение
*/

void second()
{
    cout << "Second function start" << endl;
    throw 123;
    cout << "Second function finish" << endl;
}


void first()
{
    cout << "First function start" << endl;
    second();
    cout << "First function finish" << endl;
}



int main()
{
    cout << "Main start" << endl;
    try
    {
        first();
    }
    catch (int x)
    {
        cout << "Caught. Value = " << x << endl;
    }
    cout << "Main finish" << endl;
}


/*
    Задания:
        1)  Что напечатает данная программа?

        2)  Если изменить тип аргумента в операторе catch с int на double,
            то что напечатает программа?
                catch (int x)  -->  catch (double x)
    
        3)  Если изменить тип аргумента с int на long long, то что напечатает программа?
                catch (int x)  -->  catch (long long x)

        4)  Если изменить тип аргумента с int на int&, то что напечатает программа?
                catch (int x)  -->  catch (int& x)

*/