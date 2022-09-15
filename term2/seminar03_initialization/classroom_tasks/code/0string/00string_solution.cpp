#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;


int main() 
{
    std::string all;
    std::string nextWord;

    while (true)
    {
        cin >> nextWord;
        if (nextWord == "quit")
            break;

        all += nextWord;
        cout << all << endl;
    }
}