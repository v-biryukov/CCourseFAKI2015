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

		data = (char*)malloc(sizeof(char) * (size + 1));

		// Копируем массив str в новый массив data
		for (int i = 0; str[i]; i++)
			data[i] = str[i];
		data[size] = '\0';
	}

	String()
	{
		cout << "Empty constructor" << endl;
		size = 0;
		data = (char*)malloc(sizeof(char) * (size + 1));
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
		free(data);
	}

};

ostream& operator<<(ostream& left, const String& right)
{
	left << right.c_str();
}


int main()
{
	String a = String("Cat");
	String b = "Dog"; 
	String c("Axolotl");

	// String s = a + b + c;
	// cout << s << endl;
}