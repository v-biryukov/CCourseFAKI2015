#include <iostream>
#include <cstdlib>
using namespace std;

/*
	Использовать malloc и free для создания объектов с конструкорами и деструкторами в куче не получится
	malloc просто выделяет память и не вызывает никаких конструкторов
	free просто освобождает память и не вызывает никаких деструкторов

	Для выделения памяти в куче с вызовом конструктора используется оператор new:
	String* p = new String("Hippo");

	Для освобождения памяти в куче с вызовом деструктора используется оператор delete:
	delete p;

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

	// Неправильный способ - может привести к ошибке
	// Конструктор и деструктор не вызываются
	// В данном случае мы даже память под data не выделили
	String* q = (String*)malloc(sizeof(String));
	cout << "Malloc: " << q->c_str() << endl;
	free(q);

	// Правильный способ
	String* p = new String("Hippo");
	cout << "New: " << q->c_str() << endl;
	delete p;

	/* Задание:
		1) В каком порядке будут вызываться конструкторы и деструкторы
			Запустите программу, чтобы проверить вашу догадку
		
		2) Для выделения массива элементов с помощью new:
			String* string_array = new String[10];
			При этом вызываются конструкторы String() для каждого элемента массива
			Проверьте это утверждение

		3) Для удаления массива используйте
			delete [] string_array;
			При этом вызываются деструкторы ~String() для каждого элемента массива
			Проверьте это утверждение
	*/
}