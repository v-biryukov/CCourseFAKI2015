/*
    Оператор new

    Есть вариант оператора new, который не выбрасывает исключения, а просто возвращает nullptr
    в случае ошибки. То есть работает примерно как malloc.
    
    Для этого new нужно передать объект std::nothrow в скобках.
*/

#include <iostream>
#include <cstdlib>
#include <string>
using std::cout, std::endl, std::string;



int main()
{
    int* p = new(std::nothrow) int[1'000'000'000'000];

    if (p == nullptr)
    {
        cout << "Error! Not enough memory." << endl;
        std::exit(1);
    }
}




/*
    Задачи:

        1)  Убедитесь, что new в данной программе не выбрасывается исключение,
            а программа заходит в if и печатает сообщение об ошибке.
*/