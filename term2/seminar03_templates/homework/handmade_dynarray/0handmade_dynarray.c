#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct dynarray
{
	size_t size;
	size_t capacity;
	Data* values;
};

typedef struct dynarray Dynarray;

void dynarray_init(Dynarray* pd, size_t initial_capacity)
{
	if (initial_capacity < 0)
	{
		printf("Dynarray's capacity has to be non-negative integer\n");
		exit(1);
	}
	pd->size = 0;
	pd->capacity = initial_capacity;
	pd->values = malloc(pd->capacity * sizeof(Data));
	if (pd->values == NULL)
	{
		printf("Error! Can't allocate %lu bytes of memmory using malloc()\n", pd->capacity * sizeof(Data));
		exit(1);
	}
}

void dynarray_push_back(Dynarray* pd, Data x)
{
	if (pd->size >= pd->capacity)
	{
		if (pd->capacity == 0)
			pd->capacity = 1;
		else
			pd->capacity *= 2;
		Data* temp = realloc(pd->values, pd->capacity * sizeof(int));
		if (temp == NULL)
		{
			printf("Error! Can't reallocate %lu bytes of memmory using realloc()\n", pd->capacity * sizeof(Data));
			free(pd->values);
			exit(1);
		}
		else
		{
			pd->values = temp;
		}
	}
	pd->values[pd->size] = x;
	pd->size += 1;
}

void dynarray_erase(Dynarray* pd, size_t id)
{
	if (id < 0 || id >= pd->size)
	{
		printf("Error while erasing element from Dynarray! Index is out of range\n");
		exit(1);
	}
	if (pd->size == 0)
	{
		printf("Error while erasing element from Dynarray! Dynarray is empty\n");
		exit(1);
	}
	for (size_t i = id; i < pd->size - 1; i++)
		pd->values[i] = pd->values[i + 1];
	pd->size--;
}


int dynarray_is_empty(Dynarray* pd)
{
	return (pd->size == 0);
}

void dynarray_destroy(Dynarray* pd)
{
	free(pd->values);
}


int main()
{
	Dynarray a;
	dynarray_init(&a, 0);

	for (int i = 0; i < 20; ++i)
	{
		printf("Pushing element %d. Size = %d. Capacity = %d.\n", i*i, a.size, a.capacity);
		dynarray_push_back(&a, i * i);
	}
	
	printf("Erasing 10th element\n");
	dynarray_erase(&a, 10);
	printf("10th element of Dynarray is: %d\n", a.values[10]);

	dynarray_destroy(&a);
}
