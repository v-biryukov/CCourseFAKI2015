#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main()
{
	std::string s {"Hello World"};

	cout << "String length       = " << s.size() << endl;
	cout << "sizeof(std::string) = " << sizeof(s) << endl; 

	char* p = reinterpret_cast<char*>(&s);

	for (int i = 0; i < sizeof(s); ++i)
	{
		cout << i << " : " << p[i] << " (" << static_cast<int>(p[i]) << ")" << endl;
	}

}