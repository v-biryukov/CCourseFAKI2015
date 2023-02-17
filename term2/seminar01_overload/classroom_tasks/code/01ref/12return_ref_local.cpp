/*
    Ссылки можно и возвращать из функции
    
    Но при этом нужно следить за тем, чтобы функция не вернула ссылку на локальную переменную, как это происходит в данном примере.
    После завершения функции, переменная x удалится, так как она была определена внутри функции.

    В результате, внутри функции main мы попробуем доступиться к области памяти, в которой раньше лежала переменная x.
    Это приведёт к ошибке
*/

#include <iostream>
using std::cout, std::endl;

int& get() 
{
    int x = 10;
    return x;
}


int main() 
{
    cout << get() << endl;

    get() += 1;
    cout << get() << endl;

}



/*
    Аналогичная ошибка может произойти и при работе с обычными указателями:

    int* get() 
    {
        int x = 10;
        return &x;
    }

    int main() 
    {
        cout << *get() << endl;

        *get() += 1;
        cout << *get() << endl;
    }

*/