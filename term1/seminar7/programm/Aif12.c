#include <stdio.h>
#include <math.h>

int main ()
{
    int a,b,c;     

    scanf ("%d %d %d", &a, &b, &c);
    
	// Находим максимум из 3-х сторон
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
	// Если выполняется неравенство треугольника
    if ( a + b + c > 2*max )
		if ( 2*max*max - a*a - b*b - c*c > 0 )
			printf ("obtuse\n");
		else if ( 2*max*max - a*a - b*b - c*c == 0 )
			printf("rectangular\n");
		else
			printf("acute\n");
	// иначе такого треугольника не существует
	else
		printf("impossible\n");
        
    return 0;
}
