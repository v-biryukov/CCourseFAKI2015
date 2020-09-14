#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	ifstream file;
    file.open ("leo_wp.txt");
    if (!file.is_open()) 
    	exit(1);

    string word;
    while (file >> word)
    {
        cout << word << '\n';
    }
}