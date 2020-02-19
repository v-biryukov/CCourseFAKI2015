#include <iostream>
#include <cstdlib>
using namespace std;

/*
	Деструктор
		это специальный метод, который вызывается тогда, когда объект уничтожается
		Например, если объект создан на стеке, то он уничтожается когда завершается функция
		Синтаксис деструктора такой:
		~String()
		{
			...
		}
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

	unsigned int get_size() const
	{
		return size;
	}

	const char* c_str() const
	{
		return data;
	}

};

ostream& operator<<(ostream& left, const String& right)
{
	left << right.c_str();
}


int main()
{
	String a = String("Cat"); // В данном случае будет вызываться конструктор
	String b = "Dog";         // Аналогично
	String c("Axolotl");      // Три этих способа идентичны
	
	String d {"Lion"};     // Начиная со стандарта 2011 года можно инициализировать 
						   // переменные так (используйте опцию -std=c++11 или -std=gnu++11)

	cout << a << endl << b << endl << c << endl << d << endl;

	/* Задание:
		1) Напишите деструктор, который будет освобождать память, используя free
	*/
}