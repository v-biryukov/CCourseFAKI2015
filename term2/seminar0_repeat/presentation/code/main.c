#include <stdio.h>
#include "vec.h"



int main()
{

	vec v, u;
	read(&v);
	read(&u);
	
	vec sum = add(v, u);
	print(sum);

	return 0;
}
