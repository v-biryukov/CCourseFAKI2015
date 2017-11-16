#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char ** argv)
{

	int i, n;
	time_t t;

    unsigned int max = 1000000;

	if (argc <= 1)
	{
		n = 100;
	}
	else if (argc <= 2)
	{
        sscanf(argv[1], "%d", &n);
	}
    else
    {
        sscanf(argv[1], "%d", &n);
        sscanf(argv[2], "%d", &max);
    }

	FILE * fout;
	fout = fopen("numbers.txt", "w");

	srand((unsigned) time(&t));

	fprintf(fout, "%d\n", n);
	for( i = 0 ; i < n ; i++ ) 
	{
		fprintf(fout, "%d ", rand() % max);
	}

	fclose(fout);   

	return(0);
}
