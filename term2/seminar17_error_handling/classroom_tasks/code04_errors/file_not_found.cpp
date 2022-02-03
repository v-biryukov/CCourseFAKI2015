#include <iostream>
#include <fstream>
using std::cout, std::endl;


int main()
{
    std::ifstream file;
    file.open("file.txt");
    if (!file)
    {
        cout << "File not found!" << endl;
    }
}