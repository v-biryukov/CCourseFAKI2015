/*
    Решение через substr кажется на очень эффективно, так как строка копируется каждый раз
*/

#include <iostream>
#include <stdio.h>
#include <string>
using std::cout, std::cin, std::endl;


int main()
{
    std::string s;
    cin >> s;

    for (size_t i = 1; i <= s.size(); ++i)
    {
        cout << s.substr(0, i) << endl;
    }
}
