#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 

void print_array(int* a, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%5d ", a[i]);
    printf("\n");
}
 


int is_sorted(int *a, int n)
{
  while ( --n >= 1 ) 
  {
    if ( a[n] < a[n-1] ) return 0;
  }
  return 1;
}
 
void shuffle(int *a, int n)
{
  int i, t, r;
  for(i=0; i < n; i++) 
  {
    t = a[i];
    r = rand() % n;
    a[i] = a[r];
    a[r] = t;
  }
}
 
void bogosort(int *a, int n)
{
  int iteration = 0;
  while ( !is_sorted(a, n) ) 
  {
    shuffle(a, n);
    printf("Iteration #%d:\t", iteration);
    print_array(a, n);
    iteration++;
  }
    
}


int main(int argc, char** argv)
{
  int i, n = argc - 1;
  srand(time(NULL));
  int numbers[] = { 1, 2, 3,  4, 5, 6, 7, 10, 9};
  
  for (i = 1; i < argc; i++)
  {
    sscanf(argv[i], "%d", &numbers[i-1]);
  }
 
  bogosort(numbers, n);
  printf("Sorted:   ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", numbers[i]);
  }
  printf("\n");
}