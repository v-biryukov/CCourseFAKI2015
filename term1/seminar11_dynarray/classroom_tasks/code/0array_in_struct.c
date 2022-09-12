#include <stdio.h>

struct array 
{
    size_t size;
    int values[100];
};
typedef struct array Array;

void array_push_back(Array* a, int value) 
{
    a->values[a->size] = value;
    a->size += 1;
}

int main() 
{
    Array nums;
    nums.size = 0;
}
