#include <stdio.h>

struct array 
{
    int size;
    int values[100];
};
typedef struct array Array;


void array_init(Array* a) 
{
    a->size = 0;
}


void array_push_back(Array* a, int value) 
{
    a->values[a->size] = value;
    a->size += 1;
}


int array_get(const Array* a, int index) 
{
    if (index < 0 || index >= a->size)
        printf("Error! Index is out of range\n");

    return a->values[index];
}


void array_set(Array* a, int index, int value)
{
    a->values[index] = value;
}


void array_print(const Array* a) 
{
    for (int i = 0; i < a->size; ++i) 
        printf("%i ", a->values[i]);

    printf("\n");
}

int array_is_empty(const Array* a) 
{
    return a->size == 0;
}

int main() 
{
    Array nums;
    array_init(&nums);

    array_push_back(&nums, 4);
    array_push_back(&nums, 8);
    array_push_back(&nums, 15);
    array_push_back(&nums, 16);
    array_push_back(&nums, 23);
    array_push_back(&nums, 42);

    array_set(&nums, 2, 95);
    array_print(&nums);

    printf("Second element = %d\n", array_get(&nums, 1));
}
