#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl;


void printVector(const std::vector<std::string>& v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}


void printByLetter(const std::vector<std::string>& v, char c)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].size() > 0 && v[i][0] == c)
        {
            cout << v[i] << " ";
        }
    }
    cout << '\n';
}

std::vector<std::string> getByLetter(const std::vector<std::string>& v, char c)
{
    std::vector<std::string> result;

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].size() > 0 && v[i][0] == c)
        {
            result.push_back(v[i]);
        }
    }
    return result;
}


void changeByLetter(std::vector<std::string>& v, char c)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].size() > 0 && v[i][0] == c)
        {
            v[i] = "Animal";
        }
    }
}



int main()
{
    std::vector<std::string> animals = {"Cat", "Dog", "Bison", "Rabbit", "Spider", "Wolf", "Turkey", "Lion", "Pig", "Snake", "Shark", "Bird", "Fish"};
    printVector(animals);
    printByLetter(animals, 'S');

    changeByLetter(animals, 'B');
    printVector(animals);

    std::vector<std::string> v = getByLetter(animals, 'S');
    printVector(v);
}
