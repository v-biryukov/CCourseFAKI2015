#include <iostream>
#include <cstdlib>
#include <string>
using std::cout, std::endl, std::string;


int main()
{
    string* array = new string[5]{"Cat", "Dog", "Elephant", "Bear", "Axolotl"};;

    for (int i = 0; i < 5; ++i)
        cout << array[i] << endl;

    delete[] array;
}