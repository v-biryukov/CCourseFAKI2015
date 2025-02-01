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
    const std::vector<int> a {10, 20, 30, 40, 50};
    std::vector<int> b {50, 60, 70, 80, 90};


    cout << "Before: " << endl;
    cout << "vector a = " << a << endl;
    cout << "vector b = " << b << endl;
    cout << "vector a: size = " << a.size() << ", capacity = " << a.capacity() << ", pointer = " << &a[0] << endl;
    cout << "vector b: size = " << b.size() << ", capacity = " << b.capacity() << ", pointer = " << &b[0] << endl;


    b = std::move(a);


    cout << endl << "After: " << endl;
    cout << "vector a = " << a << endl;
    cout << "vector b = " << b << endl;
    cout << "vector a: size = " << a.size() << ", capacity = " << a.capacity() << ", pointer = " << &a[0] << endl;
    cout << "vector b: size = " << b.size() << ", capacity = " << b.capacity() << ", pointer = " << &b[0] << endl;
}


/*
    Перемещение может изменять объект, из которого происходит перемещение.
    Если же этот объект является константой, то переместить из него не получится.
    В этом случае вместо перемещения происходит копирование.
*/