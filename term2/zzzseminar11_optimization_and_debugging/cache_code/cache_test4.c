
#define SIZE 100*1024*1024


// Протестируйте быстродействие без other_data и с other_data
typedef struct data
{
	int a;
	int b;
	//int other_data[10];
} Data;



int main()
{
    Data X[SIZE];
	int i;
	for ( i = 0; i < SIZE; ++i )
	{
		X[i].a = X[i].b;
	}
	return 0;
}