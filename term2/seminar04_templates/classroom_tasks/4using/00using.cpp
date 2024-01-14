/*
    using алиасы

    В языке C, чтобы дать новое имя для типа нужно было использовать typedef.
    В C++ появился новый, более удобный способ дать типы новое имя, с помощью ключевого слова using.


    Да слово using используется не только для добавления имён из пространств имён, но ещё и для того, чтобы
    давать новые имена типам. Новое имя типа также называют алиасом (англ. alias).

    В данной программе имена cat и dog это новые имена для типа unsigned long long.
*/


#include <iostream>
using std::cout, std::endl;


typedef unsigned long long cat;

using dog = unsigned long long;


int main()
{
    cat a = 123;
    dog b = 123;


    cout << a << endl;
    cout << b << endl;
}

