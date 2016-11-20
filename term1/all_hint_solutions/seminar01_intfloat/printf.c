#include <stdio.h>
int main()
{
   printf ("Characters: %c %c \n", 'a', 65);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("floats simple: %f \n", 3.1416);
   printf ("floats: %4.2f %E \n", 3.1416, 3.1416);
   printf ("%s \n", "A string");
   return 0;
}
