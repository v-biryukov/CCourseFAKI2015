#include <iostream>
#include <cstdlib>
#include <fstream>
using std::cout, std::endl;

/*


*/

int main()
{
    std::ifstream file("file.txt");
    file.exceptions(std::ifstream::failbit);

    file.close();

}