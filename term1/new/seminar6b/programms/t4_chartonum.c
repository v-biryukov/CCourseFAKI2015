#include <stdio.h>

int main ()
{
  char a;

  printf ("Enter a character : ");
  scanf ("%c", &a);

  printf ("Character %c index = %d\n", a, a);
  printf ("Previous character is %c, its index = %d\n", a-1, a-1);
  printf ("Next character is %c, its index = %d\n", a+1, a+1);
  
  return 0;
}