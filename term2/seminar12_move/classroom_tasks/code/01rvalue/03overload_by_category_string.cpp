#include <iostream>
#include <string>
using std::cout, std::endl;

/*
    В этом простом примере показывается перегрузка по категории выражения.
    Обе функции принимают вектор по ссылке и задают вектор globalNumbers
    соответствующим образом.

    Но

    - Первая функция setGlobalNumbers принимает вектор по lvalue ссылке (можно было бы использовать и const lvalue ссылку)
    В этом случае мы не хотим менять принимаемый объект, так как он может быть использован
    вне этой функции. Поэтому придётся скопировать его с помощью operator=

    - Вторая функция setGlobalNumbers принимает только rvalue объекты по rvalue-ссылке
    В этом случае мы можем менять принимаемый объект. 
    Поэтому просто перемещаем его в вектор globalNumbers, так как это более эффективно.

*/



void func(std::string& s)
{
    cout << "Pass by lvalue reference" << endl;
}


void func(std::string&& s)
{
    cout << "Pass by rvalue reference" << endl;
}



int main()
{
    std::string s1 = "Cat";
    std::string s2 = "Dog";

    func(s1);
    func(s1 + s2);
    func(s1.substr(0, 2));
}