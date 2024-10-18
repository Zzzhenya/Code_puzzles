#include <unistd.h>
#include <stdlib.h>

// #define Q 4

/*
https://www.geeksforgeeks.org/printing-solutions-n-queen-problem/
*/

int ft_strlen(char *str)
{
	int len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return(len);
}

long ft_atoi(char *str)
{
	long long n = 0;
	int i = 0;
	long long sign = 1;
	char c;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		c = str[i] - '0';
		n = n * 10 + c;
		i++;
	}
	return (n * sign);
}

#include <stdio.h> 
// int **make_grid(int n)
// {
// 	int i = 0;
// 	// int x = 1;

// 	int **arr = NULL;
// 	arr = malloc(sizeof(int *) * n);
// 	while (i < n)
// 	{
// 		arr[i] = malloc(sizeof(int) * n);
// 		int k = 0;
// 		while (k < n)
// 		{
// 			if (k == 0)
// 			{
// 				arr[i][k] = Q;
// 				// x++;
// 			}
// 			else
// 				arr[i][k] = 0;
// 			k++;
// 		}
// 		i++;
// 	}
// 	return (arr);
// }

// void	free_grid(int **arr, int n)
// {
// 	int i = 0;
// 	while (i < n)
// 	{
// 		free (arr[i]);
// 		i++;
// 	}
// 	free(arr);
// }

// void	print_grid(int **arr, int n)
// {
// 	int i = 0;
// 	while (i < n)
// 	{
// 		int j = 0;
// 		while (j < n)
// 		{
// 			printf("%d", arr[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	printf("\n");
// }


int is_valid(int n, int cord[n],int idx, int val)
{
	if (idx == 0)
		return (1);
	// go through the array
	int i = 0; 
	while (i < idx)
	{
		// take each array value (i = row cord[i] = column)
		// return 0 if in same column;
		if (cord[i] == val || i == idx)
			return (0);
		int row = idx;
		int col = val;
		// find diagonal x x
		while (row < n || col < n)
		{
			if (i == row && cord[i] == col)
				return (0);
			row++;
			col++;
		}
		row = idx;
		col = val;
		while (row < n || col >= 0)
		{
			if (i == row && cord[i] == col)
				return (0);
			row++;
			col--;
		}
		row = idx;
		col = val;
		while (row >= 0 || col < n)
		{
			if (i == row && cord[i] == col)
				return (0);
			row--;
			col++;
		}
		row = idx;
		col = val;
		while (row >= 0 || col >= 0)
		{
			if (i == row && cord[i] == col)
				return (0);
			row--;
			col--;
		}
		i++;
	}
	return (1);
}

void print_arr(int n, int cord[n])
{
	for (int i = 0; i < n; i++)
	{
		printf("row: %d\tcol: %d\t\t", i, cord[i]);
	}
	printf("\n");
}


void	process(int n, int cord[n], int row)
{
	if (row == n)
	{
		print_arr(n, cord);
		return;
	}
	// Go through each column
	int i = 0;
	while (i < n)
	{
		// check whether current row and column combination is valid
		if (is_valid(n, cord, row, i))
		{
			// if valid store the column value in the array at index row
			cord[row] = i;
			// recurse and find y value for the next row
			process(n, cord, row + 1);
		}
		i++;
	}
}

int main (int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int n = ft_atoi(argv[1]);
	write(1, argv[1], ft_strlen(argv[1]));
	write(1, "\n", 1);
	printf("n: %d\n", n);
	//int **arr = make_grid(n);
	int cord[n];
	// for (int i=0; i < n; i++)
	// 	cord[i] = 0;
	process(n, cord, 0);
	return (0);
}
