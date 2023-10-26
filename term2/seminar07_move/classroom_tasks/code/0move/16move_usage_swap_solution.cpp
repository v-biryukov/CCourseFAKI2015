#include <iostream>
#include <utility>
#include <string>
#include <vector>
using std::cout, std::endl;


template <typename T>
void swap(T& a, T& b)
{
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}


std::ostream& operator<<(std::ostream& out, const std::vector<int>& v)
{
    for (auto el : v)
        out << el << " ";
    return out;
}


int main()
{
    std::string a {"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."};
    std::string b {"Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."};


    cout << "a = " << a << endl;
    cout << "b = " << b << endl << endl;

    swap(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl << endl;




    int x = 10;
    int y = 20;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl << endl;

    swap(x, y);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl << endl;





    std::vector<int> v {10, 20, 30, 40, 50};
    std::vector<int> u {60, 70, 80, 90, 100};

    cout << "v = " << v << endl;
    cout << "u = " << u << endl << endl;
    

    swap(v, u);

    cout << "v = " << v << endl;
    cout << "u = " << u << endl << endl;
}
