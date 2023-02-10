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
    std::vector<int> b {50, 60, 70, 80, 90};


    std::vector<int> c {100, 200, 300, 400, 500};
    cout << "address of b " << &b << ", address of element of b " << &b[0] << endl;
    cout << "address of c " << &c << ", address of element of c " << &c[0] << endl;


    b = std::move(c);


    cout << "address of b " << &b << ", address of element of b " << &b[0] << endl;
}


/*
    При перемещении адрес самого объекта (&b), конечно, не изменится.
    Но адрес, по которой хранятся элементы вектора b изменятся, он станет равным адресу по которому раньше
    лежали элементы вектора c.
*/