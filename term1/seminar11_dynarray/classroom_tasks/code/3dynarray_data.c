#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef float Data;

struct dynarray {
	int capacity;
	int size;
	Data* values;
};
typedef struct dynarray Dynarray;


void dynarray_init(Dynarray* d, int initial_capacity) 
{
	d->capacity = initial_capacity;
	d->size = 0;
	d->values = (Data*)malloc(d->capacity * sizeof(Data));
}

void dynarray_push_back(Dynarray* d, Data x) 
{
	if (d->size >= d->capacity) {
		printf("Error! Dynarray is full! Can't push back any elements.\n");
		exit(1);
	}
	d->values[d->size] = x;
	d->size += 1;
}

Data dynarray_get(const Dynarray* d, int index) 
{
	if (index < 0 || index >= d->size) {
		printf("Error! Index is out of range.\n");
		exit(1);
	}
	return d->values[index];
}

void dynarray_set(Dynarray* d, int index, Data value) 
{
	if (index < 0 || index >= d->size) {
		printf("Error! Index is out of range.\n");
		exit(1);
	}
	d->values[index] = value;
}

int dynarray_is_empty(const Dynarray* d) 
{
	return d->size == 0;
}

void dynarray_destroy(Dynarray* d) 
{
	free(d->values);
}

int main() 
{
	Dynarray nums;
	dynarray_init(&nums, 1000);

	for (int i = 1; i < 20; ++i) {
		dynarray_push_back(&nums, sqrt(i));
	}

	for (int i = 0; i < nums.size; ++i) {
		printf("%.3f ", dynarray_get(&nums, i));
	}
	printf("\n");

	printf("Second element = %f\n", dynarray_get(&nums, 1));
	dynarray_destroy(&nums);
}