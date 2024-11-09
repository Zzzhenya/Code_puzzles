#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_arr(int size, int y[size])
{
	for (int i = 0; i < size; i++)
		printf("%d ", y[i]);
	printf("\n");
}

int valid(int curr, int y[curr], int val, int size)
{
	int row = curr;
	int col = val;
	while(row >= 0 && col < size)
	{
		for (int i = 0; i < curr; i++)
		{
			if (i == row && y[i] == col)
				return (0);
		}
		row--;
		col++;
	}
	row = curr;
	col = val;
	while(row < size && col >= 0)
	{
		for (int i = 0; i < curr; i++)
		{
			if (i == row && y[i] == col)
				return (0);
		}
		row++;
		col--;
	}
	row = curr;
	col = val;
	while(row >= 0 && col >= 0)
	{
		for (int i = 0; i < curr; i++)
		{
			if (i == row && y[i] == col)
				return (0);
		}
		row--;
		col--;
	}
	// row = curr;
	// col = val;
	// while(row < size && col < size)
	// {
	// 	for (int i = 0; i < curr; i++)
	// 	{
	// 		if (i == row && y[i] == col)
	// 			return (0);
	// 	}
	// 	row++;
	// 	col++;
	// }
	return (1);
}

int no_repeats(int size, int y[size], int val)
{
	for (int i = 0; i < size; i++)
	{
		if (y[i] == val)
			return (0);
	}
	return (1);
}

void	combi(int size, int y[size], int idx)
{
	if (idx == size)
	{
		print_arr(size, y);
		return;
	}
	int i = 0;
	while (i < size)
	{
		if (no_repeats(idx, y, i) && valid(idx, y, i, size))
		{
			y[idx] = i;
			combi(size, y, idx+1);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int size = atoi(argv[1]);
	// printf("%d\n", size);
	int y[size];

	combi(size, y, 0);
	return (0);
}