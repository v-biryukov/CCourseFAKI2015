#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


int main()
{
	int sudoku_arr[9][9];
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			scanf("%d", &sudoku_arr[i][j]);
			sudoku_arr[i][j] -= 1;
		}
	
	int checks[9];
	for (int i = 0; i < 9; ++i)
		checks[i] = 0;
		
	int is_sudoku = 1;
	
	// Rows
	if (is_sudoku)
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				checks[sudoku_arr[i][j]] += 1;
			}
			for (int k = 0; k < 9; ++k)
			{
				//printf("%d ", checks[k]);
				is_sudoku *= checks[k];
				checks[k] = 0;
			}
			//printf("\n");
		}
	
	// Columns
	if (is_sudoku)
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				checks[sudoku_arr[j][i]] += 1;
			}
			for (int k = 0; k < 9; ++k)
			{
				//printf("%d ", checks[k]);
				is_sudoku *= checks[k];
				checks[k] = 0;
			}
			//printf("\n");
		}
	
	// Squares
	if (is_sudoku)
		for (int i = 0; i < 9; ++i)
		{
			for (int xi = 0; xi < 3; ++xi)
			{
				for (int yi = 0; yi < 3; ++yi)
				{
					int x = 3 * (i % 3) + xi;
					int y = 3 * (i / 3) + yi;
					checks[sudoku_arr[x][y]] += 1;
				}
			}
			for (int k = 0; k < 9; ++k)
			{
				//printf("%d ", checks[k]);
				is_sudoku *= checks[k];
				checks[k] = 0;
			}
			//printf("\n");
		}
	
	if (is_sudoku)
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}
