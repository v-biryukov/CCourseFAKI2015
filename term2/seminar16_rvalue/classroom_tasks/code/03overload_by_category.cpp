#include <iostream>
#include <vector>
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




std::vector<int> globalNumbers = {1, 2, 3};

void print(const std::vector<int>& v)
{
    for (const auto& el : v)
        cout << el << " ";
    cout << endl;
}


void setGlobalNumbers(std::vector<int>& v)
{
    cout << "set by const lvalue reference called" << endl;
    globalNumbers = v;
}

void setGlobalNumbers(std::vector<int>&& v)
{
    cout << "set by rvalue reference called" << endl;
    globalNumbers = std::move(v);
}



int main()
{
    print(globalNumbers);

    std::vector<int> otherNumbers = {11, 12, 13};
    setGlobalNumbers(otherNumbers);
    print(globalNumbers);


    setGlobalNumbers(std::vector{101, 102, 103});
    print(globalNumbers);
}