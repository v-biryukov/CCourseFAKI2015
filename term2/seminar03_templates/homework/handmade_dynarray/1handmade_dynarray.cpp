#include <cstdio>
#include <cstdlib>

typedef int Data;

struct Dynarray
{
	size_t size;
	size_t capacity;
	Data* values;


	void init(size_t initial_capacity)
	{
		if (initial_capacity < 0)
		{
			printf("Dynarray's capacity has to be non-negative integer\n");
			exit(1);
		}
		size = 0;
		capacity = initial_capacity;
		values = (Data*)malloc(capacity * sizeof(Data));
		if (values == NULL)
		{
			printf("Error! Can't allocate %lu bytes of memmory using malloc()\n", capacity * sizeof(Data));
			exit(1);
		}
	}

	void push_back(Data x)
	{
		if (size >= capacity)
		{
			if (capacity == 0)
				capacity = 1;
			else
				capacity *= 2;
			Data* temp = (Data*)realloc(values, capacity * sizeof(int));
			if (temp == NULL)
			{
				printf("Error! Can't reallocate %lu bytes of memmory using realloc()\n", capacity * sizeof(Data));
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
		if (size == 0)
		{
			printf("Error while erasing element from Dynarray! Dynarray is empty\n");
			exit(1);
		}
		for (size_t i = id; i < size - 1; i++)
			values[i] = values[i + 1];
		size--;
	}


	int is_empty()
	{
		return (size == 0);
	}

	void destroy()
	{
		free(values);
	}
};

int main()
{
	Dynarray a;
	a.init(0);

	for (int i = 0; i < 20; ++i)
	{
		printf("Pushing element %d. Size = %d. Capacity = %d.\n", i*i, a.size, a.capacity);
		a.push_back(i * i);
	}

	printf("Erasing 10th element\n");
	a.erase(10);
	printf("10th element of Dynarray is: %d\n", a.values[10]);

	a.destroy();
}
