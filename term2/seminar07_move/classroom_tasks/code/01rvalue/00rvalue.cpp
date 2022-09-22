#include <iostream>
using std::cout, std::endl;




int main()
{
    //int& r = 10;
    //cout << r << endl;


    const int& cr = 10;
    cout << cr << endl;


    int&& rv = 10;
    cout << rv << endl;
}