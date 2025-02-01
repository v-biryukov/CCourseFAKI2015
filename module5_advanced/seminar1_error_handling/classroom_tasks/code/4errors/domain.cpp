#include <iostream>
#include <cmath>
#include <cerrno>
using std::cout, std::endl;


int main()
{
    if (errno == EDOM) 
        cout << "Before: errno set to EDOM\n";

    cout << std::sqrt(-1.0) << endl;

    if (errno == EDOM) 
        cout << "After: errno set to EDOM\n";

}