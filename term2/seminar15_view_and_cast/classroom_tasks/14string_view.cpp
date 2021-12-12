#include <iostream>
#include <string>
#include <string_view>

using std::cout;
using std::endl;


int main()
{
    char cstr[50] = "Hello World!!!!!!!!!!!!!";
    f(cstr);

    std::string s {cstr};

    std::string_view sv{cstr};

    cout << s << endl;
    cout << sv << endl << endl;

    cstr[0] = '%';
    cout << s << endl;
    cout << sv << endl;
 
    return 0;
}