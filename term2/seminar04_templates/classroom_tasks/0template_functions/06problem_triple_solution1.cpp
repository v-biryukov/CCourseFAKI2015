/*
    Сложность этой задачи в том, что мы не можем просто умножить строку на число.
    То есть такая функция:

    template <typename T>
    T triple(T a)
    {
        return 3 * a;
    }
    Приведёт к ошибке, так как мы не сможем умножит 3 на std::string("cat")


    Простейшее решение в этой ситуации: просто сложить 3 раза.
*/

#include <iostream>
#include <string>
using std::cout, std::endl;


template <typename T>
T triple(T a)
{
    return a + a + a;
}


int main() 
{
    cout << triple(3) << endl;
    cout << triple(1.5) << endl;


    cout << triple(std::string("cat")) << endl;
}


