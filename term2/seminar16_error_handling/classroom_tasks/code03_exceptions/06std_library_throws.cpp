#include <iostream>
#include <exception>
using std::cout, std::endl;


/*


*/


void func() noexcept
{
    throw 123;
}


int main()
{
    int* p = nullptr;

    cout << *p << endl;
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