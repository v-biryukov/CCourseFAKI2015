#include <vector>
#include <iostream>
#include <utility>
using std::cout, std::endl;

// Вспомагательная функция для вывода вектора на экран
std::ostream& operator<<(std::ostream& out, const std::vector<int>& v)
{
    for (auto el : v)
        out << el << " ";
    return out;
}

int main()
{
    std::vector<int> a {50, 60, 70, 80, 90};


    std::vector<int> b {100, 200, 300, 400, 500};
    cout << "address of a " << &a << ", address of element of a " << &a[0] << endl;
    cout << "address of b " << &b << ", address of element of b " << &b[0] << endl;


    a = std::move(b);


    cout << "address of a " << &a << ", address of element of a " << &a[0] << endl;
}


/*
    При перемещении адрес самого объекта (&a), конечно, не изменится.
    Но адрес, по которой хранятся элементы вектора a изменятся, он станет равным адресу по которому раньше
    лежали элементы вектора b.
*/