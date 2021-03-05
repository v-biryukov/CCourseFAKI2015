#include <iostream>
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
		size = 0;
		while (str[size])
			size++;

		data = new char[size + 1];

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
		data = new char[1];
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
		// Вычисляем размер новой строки
		unsigned int sum_size = size + right.get_size();

		// Выделяем память под новую строку необходимого размера
		char* sum_data = new char[sum_size + 1];

		// Заполняем строку строками операндами
		for (int i = 0; i < size; i++)
			sum_data[i] = data[i];
		for (int i = size; i < sum_size; i++)
			sum_data[i] = right.data[i - size];
		//Не забываем поставить 0 в конце строки
		sum_data[sum_size] = '\0';
		
		// Нам нужно вернуть новый экземпляр класса String
		// Поэтому создаём его:
		String result(sum_data);
		// Освобождаем вспомогательный массив sum_data
		delete [] sum_data;
		// Возвращаем
		return result;
	}

	String& operator+=(const String& right)
	{
		// Делаем то же самое, что и в operator+
		unsigned int sum_size = size + right.get_size();
		
		char* sum_data = new char[sum_size + 1];
		for (int i = 0; i < size; i++)
			sum_data[i] = data[i];
		for (int i = size; i < sum_size; i++)
			sum_data[i] = right.data[i - size];
		sum_data[sum_size] = '\0';

		delete [] data;
		data = sum_data;
		size = sum_size;
		// Возвращаем текущий экземпляр (Помните, что operator+= всегда возвращает ссылку на левый аргумент)
		return *this;
	}


	String& operator=(const String& right)
	{
		// Проверяем случай присваивания строки с самой собой  (a = a)
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

		// Возвращаем текущий экземпляр (Помните, что operator= всегда возвращает ссылку на левый аргумент)
		return *this;
	}

	// Этот оператор возвращает ссылку, благодаря этому
	// мы можем изменять содержимое массива
	// То есть писать так array[i] = ...
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
	// Создали класс String, с которым гораздо удобней работать,
	// чем со строками в стиле C
	String a = "Cat";
	String b = "Dog"; 
	String c = "Axolotl";
	String d = "Cat";

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	String x = a + b;
	cout << "x = a + b; x = " << x << endl;

	x += c;
	cout << "x += c; x = " << x << endl;

	cout << "d == a: " << (d == a) << endl;
	cout << "c == a: " << (c == a) << endl;

	x[7] = '%';
	cout << "Changing x[7]. x = " << x << endl;

	cout << "Trying to chang x[100] (out of bounds) with operator[] (not safe)" << endl;
	x[100] = 'A';

	cout << "Trying to chang x[100] (out of bounds) with at (safe)" << endl;
	x.at(100) = 'B';
}