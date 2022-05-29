#include <iostream>
using std::cout, std::endl;




void calculateLetters(char str[], int& numLetters)
{
    numLetters = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            numLetters += 1;
    }
}

int main() 
{
    int x;
    calculateLetters("ab54AB,gd1:e", x);
    cout << x << endl;
}

