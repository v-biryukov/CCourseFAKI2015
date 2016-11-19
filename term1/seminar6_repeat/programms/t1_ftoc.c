#include <stdio.h>

int main ()
{
  double Tf;
  double Tc;

  printf ("Enter the temperature in Fahrenheit: ");
  scanf ("%lf", &Tf); 
  Tc = 5.0/9.0*(Tf-32);
  printf ("Temperature in Celsius: %lf \n", Tc);
  
  return 0;
}