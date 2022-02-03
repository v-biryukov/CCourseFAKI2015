#include <iostream>
#include <string>
using std::cout, std::endl;


void func(std::string s)
{
    cout << &s << ", " << (void*)&s[0] << endl;
}


std::string&& printAddressAndReturn(std::string&& s)
{
    cout << &s << ", " << (void*)&s[0] << endl;
    return std::move(s);
}


int main()
{
    std::string s1 = "Long long long long long string (no small string optimization)";
    std::string s2 = "Another string that is longer than 16 symbols";

    // cout << "Initial:\t" << &s << ", " << (void*)&s[0] << endl;


    //cout << "Pass by copy:\t";
    func(printAddressAndReturn(std::move(s1)));

}

