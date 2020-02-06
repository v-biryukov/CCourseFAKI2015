#include <cstdio>
#include <cstdlib>

template<typename T>
struct Dynarray
{
	size_t size;
	size_t capacity;
	T* values;

	Dynarray(size_t initial_capacity)
	{
		size = 0;
		capacity = initial_capacity;
		values = (T*)malloc(capacity * sizeof(T));
		if (values == NULL)
		{
			printf("Error! Can't allocate %lu bytes of memmory using malloc()\n", capacity * sizeof(T));
			exit(1);
		}
	}

	Dynarray() : Dynarray(0)
	{
	}

	~Dynarray()
	{
		free(values);
	}

	void push(T x)
	{
		if (size >= capacity)
		{
			if (capacity == 0)
				capacity = 1;
			else
				capacity *= 2;
			T* temp;
			temp = (T*)realloc(values, capacity * sizeof(int));
			if (temp == NULL)
			{
				printf("Error! Can't reallocate %lu bytes of memmory using realloc()\n", capacity * sizeof(T));
				free(values);
				exit(1);
			}
			else
			{
				values = temp;
			}
		}
		values[size] = x;
		size += 1;
	}

	T pop()
	{
		if (size == 0)
		{
			printf("Error! Dynarray is empty! Can't pop any elements\n");
			exit(1);
		}
		size -= 1;
		return values[size];
	}


	int is_empty() const
	{
		return size == 0;
	}

	T operator()(size_t i)
	{
		return values[i];
	}

	T& operator[](size_t i)
	{
		return values[i];
	}

	T& at(size_t i)
	{
		if (i >= size)
		{
			printf("Error! Dynarray index is out of bounds.\n");
			exit(1);
		}
		return values[i];
	}
};


int main()
{
	Dynarray<int> a;

	for (int i = 0; i < 100; ++i)
		a.push(i*i);

	printf("Size = %d. Capacity = %d\n", a.size, a.capacity);

	printf("Round brackets:  %d\n", a(16));	
	printf("Square brackets: %d\n", a[16]);

	//  a(16) = 55;  // Это не будет работать

	a[16] = 55; // Это будет работать, так как operator[] возвращает ссылку
	printf("Changing element %d\n", a[16]);

	// Пытаемся выйти за пределы массива
	printf("Out of bounds. Operator square brackets: %d\n", a[200]);
	printf("Out of bounds. Function at: %d\n", a.at(200));
	// Функция at - медленней, но безопасней, так как обрабатывает ошибки


	Dynarray<float> b;
	b.push(1.45);
	b.push(7.77);
	b.push(5.32);
	b.push(5.60);
	b[1] = 2.86;
	for (int i = 0; i < b.size; i++)
		printf("%.2f ", b[i]);
}
