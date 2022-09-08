#include <iostream>
#include <string>
using std::cout, std::endl;


void changeLetters(std::string& word, char letter, char newLetter)
{
    for (int i = 0; i < word.size(); ++i)
    {
        if (word[i] == letter)
            word[i] = newLetter;
    }
}



int main()
{
    std::string a = "Hello";
    cout << a << endl;

    changeLetters(a, 'e', 'a');
    cout << a << endl;

    changeLetters(a, 'l', 'p');
    cout << a << endl;
}