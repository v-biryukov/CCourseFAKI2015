#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "dynarray.h"

int main() 
{
    Dynarray nums;
    dynarray_init(&nums, 1000);

    for (int i = 1; i < 20; ++i) 
        dynarray_push_back(&nums, i);


    for (int i = 0; i < nums.size; ++i) 
        printf("%i ", dynarray_get(&nums, i));
    printf("\n");

    printf("Second element = %i\n", dynarray_get(&nums, 1));
    dynarray_destroy(&nums);
}