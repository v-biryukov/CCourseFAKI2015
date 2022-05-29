#include <iostream>
#include <thread>
using std::cout, std::cin, std::endl;



int main()
{
    std::thread a {[](){cout << "Hello" << endl;}};
    a.join();
}


/*
    Задача:
        
        Проверьте, можно ли инициализировать объект std::thread с помощью функтора:

        struct Functor
        {
            operator()()
            {
                cout << "Hello from Functor";
            }
        };

*/