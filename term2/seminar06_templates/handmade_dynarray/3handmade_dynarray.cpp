#include <cstdio>
#include <cstdlib>


template <typename T>
struct Dynarray
{
	size_t size;
	size_t capacity;
	T* values;


	Dynarray(size_t initial_capacity)
	{
		if (initial_capacity < 0)
		{
			printf("Dynarray's capacity has to be non-negative integer\n");
			exit(1);
		}
		size = 0;
		capacity = initial_capacity;
		values = (T*)malloc(capacity * sizeof(T));
		if (values == NULL)
		{
			printf("Error! Can't allocate %lu bytes of memmory using malloc()\n", capacity * sizeof(T));
			exit(1);
		}
	}

	void push(T x)
	{
		if (size >= capacity)
		{
			if (capacity == 0)
				capacity = 1;
			else
				capacity *= 2;
			T* temp = (T*)realloc(values, capacity * sizeof(int));
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

	void erase(size_t id)
	{
		if (id < 0 || id >= size)
		{
			printf("Error while erasing element from Dynarray! Index is out of range\n");
			exit(1);
		}
		for (size_t i = id; i < size - 1; i++)
			values[i] = values[i + 1];
	}


	int is_empty()
	{
		return (size == 0);
	}

	~Dynarray()
	{
		free(values);
	}
};

int main()
{
	Dynarray<int> a(0);

	for (int i = 0; i < 100; ++i)
	{
		printf("Pushing element %d. Size = %d. Capacity = %d.\n", i*i, a.size, a.capacity);
		a.push(i * i);
	}
	a.erase(50);
	printf("50th element of Dynarray is: %d\n", a.values[50]);

}
