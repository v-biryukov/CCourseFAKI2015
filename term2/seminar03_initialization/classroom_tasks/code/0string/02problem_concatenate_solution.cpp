#include <iostream>
#include <string>
using std::cout, std::endl;


std::string concatenate(const std::string words[], int numOfWords)
{
    std::string result;

    for (int i = 0; i < numOfWords; ++i)
        result += words[i];

    return result;
}



int main()
{
    std::string animals[5] = {"Cat", "Dog", "Mouse", "Axolotl", "Lion"};

    cout << concatenate(animals, 5) << endl;
}