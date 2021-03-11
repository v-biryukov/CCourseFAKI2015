#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

/*
	Класс Number -- класс положительных больших чисел

	Большое число будет храниться в динамическом массиве data
	Каждый элемент этого массива содержит разряд числа в 100-ричной системе счисления
	(так как base = 100)
	По сути, каждый элемент data хранит две цифры числа в десятичной записи

	Значение 100 для системы счисления выбрано как компромис между
	эффективностью и удобством написания программы.
	Если выбрать значения базы 10 - то программа будет не так эффективна по памяти
	Если выбрать значения базы 256 (максимально эффективное использование памяти для типа char),
	то алгоритм печати на экран сильно усложнится

	capacity - размер массива data
	size - сколько ячеек занимет число в массиве data
	size <= capacity
	
	Для удобства разряды числа хранятся в обратном порядке
	Например, число 12345678 соответствует массиву
	data = {78, 56, 34, 12}
	(это упрощает многие алгоритмы с такими числами)
*/


struct Number
{
private:
	static const int base = 100;
	int size;
	int capacity;
	char* data;

public:
	// Конструктор, который создаёт наше число из числа типа int
	Number(int a)
	{
		// Находим размер необходимой памяти под это число
		int temp = a;
		capacity = 0;
		while (temp != 0)
		{
			temp /= base;
			capacity += 1;
		}
		// Отдельно обрабатываем случай, когда число равно 0
		if (capacity == 0)
			capacity = 1;
		// Выделяем память
		data = new char[capacity];
		// Записывем число a в массив data
		// Например, число 12345678 представится в виде массива [78, 56, 34, 12]
		for (int i = 0; i < capacity; ++i)
		{
			data[i] = a % base;
			a /= base;
		}
		// В данном случае размер будет равен вместимости
		size = capacity;
	}

	Number operator+(const Number& right) const
	{
		// Создаём новое число, в котором будем хранить результат сложения
		Number result{ 0 };
		result.capacity = std::max(size, right.size) + 1;
		result.data = new char[result.capacity];

		// Складываем
		// Идём с конца числа, то есть с начала массива data
		int carry = 0;
		for (int i = 0; i < result.capacity - 1; ++i)
		{
			// Находим сумму текущих разрядов
			// с учётом переноса с предыдущего разряда (carry)
			int sum = 0;
			if (i < capacity)
				sum += data[i];
			if (i < right.capacity)
				sum += right.data[i];
			sum += carry;

			// Записываем результат (< 100) в новое число
			// Сотни переносим в следующий разряд (carry)
			result.data[i] = sum % base;
			carry = sum / base;
		}
		result.data[result.capacity - 1] = carry;

		// Если последний разряд будет равен нулю,
		// то размер числа будет на 1 меньше, чем capacity
		if (carry != 0)
			result.size = result.capacity;
		else
			result.size = result.capacity - 1;

		return result;
	}

	Number& operator=(const Number& right)
	{
		// Проверяем не являются ли левая и правые части тем же самым числом
		// Для этого сравниваем адресы объектов
		if (&right == this)
		{
			return *this;
		}

		// Если это разные объекты, то удаляем всё в левом объекте
		// и присваиваем содержимое правого
		delete[] data;
		capacity = right.capacity;
		data = new char[capacity];
		for (int i = 0; i < capacity; ++i)
		{
			data[i] = right.data[i];
		}
		size = right.size;

		// Не забываем, что оператор присваивания возвращает ссылку на сам объект
		return *this;
	}

	void print_info()
	{
		std::cout << "Size = " << size << std::endl;
		for (int i = 0; i < size; ++i)
		{
			std::cout << data[i] << std::endl;
		}
	}

	// Дружественная функция печати на экран
	friend std::ostream& operator<<(std::ostream& stream, const Number& right);
};


// Печать нашего числа на экран
// Эта функция может использовать приватные поля, так как она дружественная
std::ostream& operator<<(std::ostream& stream, const Number& right)
{
	// Печатаем самый большой разряд
	stream << (int)right.data[right.size - 1];
	// Печатаем остальные разряды с заполнением нулями до 2-х цифр
	// setfill и setw это то же самое, что и в языке C спецификатор %02d
	for (int i = right.size - 2; i >= 0; --i)
	{
		stream << std::setfill('0') << std::setw(2) << (int)right.data[i];
	}
	return stream;
}



int main()
{
	
	Number x = 12345;
	Number y = 800;
	Number z = x + y;
	std::cout << z << std::endl;
}