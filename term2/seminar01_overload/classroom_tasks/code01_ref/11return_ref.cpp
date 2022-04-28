#include <iostream>
using std::cout, std::endl;


/*
    Ссылки можно и возвращать из функции
    Например, функция get возвращает ссылку на глобальную переменную x

*/

int x = 10;


int& get() 
{
    return x;
}

int main() 
{
    cout << x << endl;
    cout << get() << endl;

    get() += 1;
    cout << x << endl;
}



/*
    С указателями аналогичный код выглядел бы так:


int x = 10;

int* get() 
{
    return &x;
}

int main() 
{
    cout << x << endl;
    cout << *get() << endl;

    *get() += 1;
    cout << x << endl;
}

*/