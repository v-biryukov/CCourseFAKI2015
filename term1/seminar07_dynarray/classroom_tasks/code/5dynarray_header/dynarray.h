#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int Data;

struct dynarray 
{
	size_t capacity;
	size_t size;
	Data* values;
};
typedef struct dynarray Dynarray;


void dynarray_init(Dynarray* d, size_t initial_capacity) 
{
	d->capacity = initial_capacity;
	d->size = 0;
	d->values = (Data*)malloc(d->capacity * sizeof(Data));
}


void dynarray_push_back(Dynarray* d, Data x) 
{
	if (d->size >= d->capacity) 
    {
		printf("Error! Dynarray is full! Can't push back any elements.\n");
		exit(1);
	}
	d->values[d->size] = x;
	d->size += 1;
}


Data dynarray_get(const Dynarray* d, size_t index) 
{
	if (index < 0 || index >= d->size) 
    {
		printf("Error! Index is out of range.\n");
		exit(1);
	}
	return d->values[index];
}


void dynarray_set(Dynarray* d, size_t index, Data value) 
{
	if (index < 0 || index >= d->size) 
    {
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