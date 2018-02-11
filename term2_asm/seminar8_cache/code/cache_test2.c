
#define SIZE 100*1024*1024

typedef struct data
{
	int a;
	int b;
	//int other_data[10];
} Data;

Data X[SIZE];

int main()
{
	int i;
	for ( i = 0; i < SIZE; ++i )
	{
		X[i].a = X[i].b;
	}
	return 0;
}