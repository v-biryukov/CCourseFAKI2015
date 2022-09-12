#include <stdio.h>
#include <stdlib.h>

struct dynarray 
{
    size_t capacity;
    size_t size;
    int* values;
};
typedef struct dynarray Dynarray;


void dynarray_init(Dynarray* d, size_t initial_capacity) 
{
    d->capacity = initial_capacity;
    d->size = 0;
    d->values = (int*)malloc(d->capacity * sizeof(int));
}


void dynarray_push_back(Dynarray* d, int x) 
{
    d->values[d->size] = x;
    d->size += 1;
}

int dynarray_get(const Dynarray* d, size_t index) 
{
    return d->values[index];
}


void dynarray_set(Dynarray* d, size_t index, int value) 
{
    d->values[index] = value;
}


void dynarray_print(const Dynarray* d) 
{
    for (int i = 0; i < d->size; ++i) 
        printf("%i ", d->values[i]);

    printf("\n");
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

    dynarray_push_back(&nums, 4);
    dynarray_push_back(&nums, 8);
    dynarray_push_back(&nums, 15);
    dynarray_push_back(&nums, 16);
    dynarray_push_back(&nums, 23);
    dynarray_push_back(&nums, 42);

    dynarray_set(&nums, 2, 95);

    dynarray_print(&nums);

    printf("Second element = %d\n", dynarray_get(&nums, 1));

    dynarray_destroy(&nums);
}
