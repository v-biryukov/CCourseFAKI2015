#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXN 2000000


int main(int argc, char ** argv)
{

	int i, n;
	time_t t;

	if (argc <= 1)
	{
		n = 100;
	}
	else
	{
		char * ptr;
		n = strtol(argv[1], &ptr, 10);
	}

	FILE * fout;
	fout = fopen("numbers.txt", "w");


	/* Intializes random number generator */
	srand((unsigned) time(&t));

	fprintf(fout, "%d\n", n);
	for( i = 0 ; i < n ; i++ ) 
	{
		fprintf(fout, "%d ", rand() % MAXN);
	}

	fclose(fout);   

	return(0);
}
