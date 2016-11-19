#include <stdio.h>
#include <stdlib.h> 

int main ()
{

  double p1x, p1y, p2x, p2y, p3x, p3y;


  printf ("Enter coordinates of the 1st point: \n");
  scanf ("%lf", &p1x);  
  scanf ("%lf", &p1y);

  printf ("Enter coordinates of the 2nd point: \n");
  scanf ("%lf", &p2x);  
  scanf ("%lf", &p2y);  

  printf ("Enter coordinates of the 3rd point: \n");
  scanf ("%lf", &p3x);  
  scanf ("%lf", &p3y);


  double S = 0.5 * abs((p2x-p1x)*(p3y-p1y) - (p2y-p1y)*(p3x-p1x));
  printf ("Area of the triangle: %lf \n", S );


  return 0;
}