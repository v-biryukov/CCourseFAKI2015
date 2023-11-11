#include <iostream>
#include <cctype>
using std::cout, std::endl;


void calculateLetters(const char str[], int& numLetters)
{
    numLetters = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (isalpha(str[i]))
            numLetters += 1;
    }
}

int main() 
{
    int x;
    calculateLetters("ab54AB,gd1:e", x);
    cout << x << endl;
}

