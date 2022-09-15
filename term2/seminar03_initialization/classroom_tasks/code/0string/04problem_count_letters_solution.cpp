/*
    Можно было использовать функцию isalpha.
*/

#include <iostream>
#include <string>
using std::cout, std::endl;


int countLowerLetters(const std::string& str)
{
    int result = 0;

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            result += 1;
    }

    return result;
}



int main()
{
    std::string a = "Hello123Cat!";
    cout << countLowerLetters(a) << endl;
}