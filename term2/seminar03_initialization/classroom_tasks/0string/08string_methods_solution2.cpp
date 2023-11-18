#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;


int main()
{
    std::string line;
    std::getline(cin, line);

    size_t id = -1;

    while (true)
    {
        id = line.find("cat", id + 1);
        if (id == std::string::npos)
            break;

        cout << id << " ";
    }
    cout << endl;
}