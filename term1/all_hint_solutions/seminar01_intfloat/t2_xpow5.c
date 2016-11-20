#include <stdio.h>

int main ()
{
  double x;
  int n;

  printf ("Enter a number x: ");
  scanf ("%lf", &x);
  printf ("Enter a precision: ");
  scanf ("%d", &n);

  printf ("pow(x, 5) = %*.*lf \n", 5, n, x*x*x*x*x);
  
  return 0;
}