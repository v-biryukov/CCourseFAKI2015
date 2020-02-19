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
		cout << "Constructor: " << str << endl;
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

	~String()
	{
		cout << "Destructor: " << data << endl;
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



	/* Задание:
		1) В каком порядке будут вызываться конструкторы и деструкторы
			Запустите программу, чтобы проверить вашу догадку

		2) Предположим, что мы захотели создать саму структуру String (а не только массив data)
			Вот так:
				String* s = (String*)malloc(sizeof(String));
			Какой конструктор вызовится в этом случае?

			А потом освободить
				free(s);
			Вызовится ли деструктор в этом случае
	*/
}