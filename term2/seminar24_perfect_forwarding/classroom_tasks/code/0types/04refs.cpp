/*
    Именнованные rvalue ссылки очень похожи на lvalue ссылки

    Различие есть в инициализации таких ссылок, но в большинстве
    случаев rvalue ссылка очень похожа на lvalue-ссылку

    В частности выражение состоящее только из rvalue-ссылки является lvalue выражением
*/


#include <iostream>
using std::cout, std::endl;



void printValueType(int& x)
{
    cout << "Lvalue" << endl;
}

void printValueType(int&& x)
{
    cout << "Rvalue" << endl;
}


int main()
{
    int a = 5;

    printValueType(a);
    printValueType(5);

    int&  r1 = a;
    int&& r2 = 10;

    printValueType(r1);
    printValueType(r2);
}


/*
    Что напечатает данная программа?

*/
