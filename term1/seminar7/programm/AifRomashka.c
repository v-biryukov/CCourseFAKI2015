#include <stdio.h>
#include <math.h>


int main ()
{
    int n;     
    scanf ("%d", &n);
	
	if (n < 2)
		printf("%d\n", 0);
	else if (n < 5)
		printf("%d\n", 1);
	else
		printf("%d\n", 2);
		
    return 0;
}
