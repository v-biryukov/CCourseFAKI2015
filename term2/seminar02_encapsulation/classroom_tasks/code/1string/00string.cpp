#include <iostream>
#include <cstdlib>
using namespace std;

// Создадим класс строки
// Такой чтобы можно было удобно создавать строки, приравнивать, складывать и сравнивать
// (Библиотекой string.h не пользуемся, чтобы наша строка не зависела от старой библиотеки)

// Будем сразу хранить в структуре размер нашей строки
struct String
{
	unsigned int size;
	char* data;
};

ostream& operator<<(ostream& left, const String& right)
{
	left << right.data;
}


int main()
{
	
	String a = {3, "Cat"};

	char str[] = "Fox";
	String b = {3, str};

	cout << a << endl << b << endl;
	/*
		Этот код вроде работает, но у наших строк a и b есть недостатки
		1) В чём недостаток строки a?

		2) В чём недостаток строки b?
	*/
}