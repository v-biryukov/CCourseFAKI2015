/*
    Есть третье решение этой задачи.

    Если мы просто напишем перегруженный оператор умножения для типов int и std::string,
    то проблемы с умножением строки в шаблонной функции не возникнет.
*/




#include <iostream>
#include <string>
using std::cout, std::endl;


std::string operator*(int n, const std::string& s)
{
    std::string result {};

    for (int i = 0; i < n; ++i)
        result += s;

    return result;
}

template <typename T>
T triple(T a)
{
    return 3 * a;
}


int main() 
{
    cout << triple(3) << endl;
    cout << triple(1.5) << endl;

    cout << triple(std::string("cat")) << endl;
}
