#include <iostream>
#include <cstdlib>
using namespace std;

/*
	Напишите operator+ для строки
*/

struct String
{
private:
	unsigned int size;
	char* data;

public:

	String(const char* str)
	{
		// Находим размер строки str (strlen не будем пользоваться)
		size = 0;
		while (str[size])
			size++;

		data = new char[size + 1];

		// Копируем массив str в новый массив data
		for (int i = 0; str[i]; i++)
			data[i] = str[i];
		data[size] = '\0';
	}

	String()
	{
		size = 0;
		data = new char;
		data[0] = '\0';
	}

	unsigned int get_size() const
	{
		return size;
	}

	const char* c_str() const
	{
		return data;
	}

	~String()
	{
		delete [] data;
	}

};

ostream& operator<<(ostream& left, const String& right)
{
	left << right.c_str();
	return left;
}


int main()
{
	String a = String("Cat");
	String b = "Dog"; 
	String c("Axolotl");

	// String s = a + b + c;
	// cout << s << endl;
}