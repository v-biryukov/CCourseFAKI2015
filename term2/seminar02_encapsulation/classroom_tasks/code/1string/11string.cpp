#include <iostream>
#include <cstdlib>
using namespace std;

// (Библиотекой string.h не пользуемся, чтобы наша строка не зависела от старой библиотеки)

struct String
{
private:
	unsigned int size;
	char* data;

public:
	String(const char* str)
	{
		// Находим размер строки str 
		size = 0;
		while (str[size])
			size++;

		data = (char*)malloc(sizeof(char) * (size + 1));

		// Копируем массив str в новый массив data
		for (int i = 0; str[i]; i++)
			data[i] = str[i];
		data[size] = '\0';
	}

	String(const String& str) : String(str.c_str())
	{
	}

	String()
	{
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

	String operator+(const String& right) const
	{
		unsigned int sum_size = size + right.get_size();

		char* sum_data = (char*)malloc(sizeof(char) * (sum_size + 1));
		for (int i = 0; i < size; i++)
			sum_data[i] = data[i];
		for (int i = size; i < sum_size; i++)
			sum_data[i] = right.data[i - size];
		sum_data[sum_size] = '\0';
		
		String result(sum_data);
		free(sum_data);
		return result;
	}

	String& operator+=(const String& right)
	{
		unsigned int sum_size = size + right.get_size();
		
		char* sum_data = (char*)malloc(sizeof(char) * (sum_size + 1));
		for (int i = 0; i < size; i++)
			sum_data[i] = data[i];
		for (int i = size; i < sum_size; i++)
			sum_data[i] = right.data[i - size];
		sum_data[sum_size] = '\0';

		free(data);
		data = sum_data;
		size = sum_size;
		return *this;
	}


	String& operator=(const String& right)
	{
		// Проверяем случай приравнивания строки с самой собой  (a = a)
		// Помните, что this - это указатель на экземпляр данного класса
		// &right - это адрес правой строки, this - адрес левой
		if (&right == this)
			return *this;

		// Выделяем память под данные для новой строки и задаём их
		unsigned int new_size = right.get_size();
		char* new_data = (char*)malloc(sizeof(char) * (new_size + 1));
		for (int i = 0; i < new_size; i++)
			new_data[i] = right.data[i];
		new_data[new_size] = '\0';
		
		// Удаляем старые данные и приравниваем data к новым данным
		free(data);
		data = new_data;
		size = new_size;

		// Возвращаем текущий экземпляр (Помните, что operator= всегда возвращает новый левый аргумент)
		return *this;
	}

	char& operator[](unsigned int id)
	{
		return data[id];
	}

	char& at(unsigned int id)
	{
		if (id < 0 || id > size)
		{
			cout << "Error! String index is out of boundary!" << endl;
			exit(1);
		}
		return data[id];
	}

	bool operator==(const String& right) const
	{
		if (size != right.size)
			return false;

		for (int i = 0; i < size; i++)
			if (data[i] != right.data[i])
				return false;

		return true;
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

	String x = a + b;
	x += c;
	x[7] = '%';
	cout << x << endl;
	x[100] = 'A';
	x.at(100) = 'B';
}