/*
Place N queens on a NxN chess board so that
no two queens attack each other

*/
#include <unistd.h>
#include <stdlib.h>

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
int **make_grid(int n)
{
	int i = 0;

	int **arr = NULL;
	arr = malloc(sizeof(int *) * n);
	while (i < n)
	{
		arr[i] = malloc(sizeof(int) * n);
		int k = 0;
		while (k < n)
		{
			arr[i][k] = 0;
			k++;
		}
		i++;
	}
	return (arr);
}

void	free_grid(int **arr, int n)
{
	int i = 0;
	while (i < n)
	{
		free (arr[i]);
		i++;
	}
	free(arr);
}

void	print_grid(int **arr, int n)
{
	int i = 0;
	while (i < n)
	{
		int j = 0;
		while (j < n)
		{
			printf("%d", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

int has_n_queens(int **arr, int n)
{
	int i = 0;
	int count = 0;
	while (i < n)
	{
		int j = 0;
		while (j < n)
		{
			if (arr[i][j] == 4)
				count++;
			j++;
		}
		i++;
	}
	if (count == n)
		return (1);
	else
		return (0);
}

int	usable(int **arr, int n, int i, int j)
{
	//int check = 0;

	//check current loc

	if (arr[i][j] == 4)
		return (0);
	if (arr[i][j] == 1)
		return (0);
	// +
	// line
	int row = i;
	int col = 0;
	while (col < n)
	{
		if (arr[row][col] == 4 )//|| arr[i][j] == 1)
			return (0);
		col++;
	}
	row = 0;
	col = j;
	while (row < n)
	{
		if (arr[row][col] == 4 )//|| arr[i][j] == 1)
			return (0);
		row ++;
	}
	row = i; col = j;
	while (row > 0 && col > 0)
	{
		if (arr[row][col] == 4 )//|| arr[row][col] == 1)
			return (0);
		row--;
		col--;
	}
	row = i; col = j;
	while (row < n && col < n)
	{
		if (arr[row][col] == 4 )//|| arr[row][col] == 1)
			return (0);
		row++;
		col++;
	}
	row = i; col = j;
	while (row > 0 && col < n)
	{
		if (arr[row][col] == 4 )//|| arr[row][col] == 1)
			return (0);
		row--;
		col++;
	}
	row = i; col = j;
	while (row < n && col > 0)
	{
		if (arr[row][col] == 4 )//|| arr[row][col] == 1)
			return (0);
		row++;
		col--;
	}
	return (1);
}

void mark_unusable(int **arr, int n, int i , int j)
{
	int row = i;
	int col = 0;
	while (col < n)
	{
		if (arr[row][col] != 4)
			arr[row][col] = 1;
		col++;
	}
	row = 0;
	col = j;
	while (row < n)
	{
		if (arr[row][col] != 4)
			arr[row][col] = 1;
		row ++;
	}
	row = i; col = j;
	while (row > 0 && col > 0)
	{
		if (arr[row][col] != 4)
			arr[row][col] = 1;
		row--;
		col--;
	}
	row = i; col = j;
	while (row < n && col < n)
	{
		//if (row != i && col != j)
		if (arr[row][col] != 4)
			arr[row][col] = 1;
		row++;
		col++;
	}
	row = i; col = j;
	while (row > 0 && col < n)
	{
		if (arr[row][col] != 4)
			arr[row][col] = 1;
		row--;
		col++;
	}
	row = i; col = j;
	while (row < n && col > 0)
	{
		if (arr[row][col] != 4 )
			arr[row][col] = 1;
		row++;
		col--;
	}
}

void mark_usable(int **arr, int n, int i , int j)
{
	int row = i;
	int col = 0;
	while (col < n)
	{
		if (arr[row][col] == 1)
			arr[row][col] = 0;
		col++;
	}
	row = 0;
	col = j;
	while (row < n)
	{
		if (arr[row][col] == 1)
			arr[row][col] = 0;
		row ++;
	}
	row = i; col = j;
	while (row > 0 && col > 0)
	{
		if (arr[row][col] == 1)
			arr[row][col] = 0;
		row--;
		col--;
	}
	row = i; col = j;
	while (row < n && col < n)
	{
		if (arr[row][col] == 1)
			arr[row][col] = 0;
		row++;
		col++;
	}
	row = i; col = j;
	while (row > 0 && col < n)
	{
		if (arr[row][col] == 1)
			arr[row][col] = 0;
		row--;
		col++;
	}
	row = i; col = j;
	while (row < n && col > 0)
	{
		if (arr[row][col] == 1 )
			arr[row][col] = 0;
		row++;
		col--;
	}
}

int	ok(int **arr, int n, int i, int j)
{
	//int check = 0;

	//check current loc

	// if (arr[i][j] == 4)
	// 	return (0);
	// if (arr[i][j] == 1)
	// 	return (0);
	// +
	// line
	int row = i;
	int col = 0;
	while (col < n)
	{
		if (arr[row][col] == 4  && row != i && col != j)//|| arr[i][j] == 1)
			return (0);
		col++;
	}
	row = 0;
	col = j;
	while (row < n)
	{
		if (arr[row][col] == 4 && row != i && col != j)//|| arr[i][j] == 1)
			return (0);
		row ++;
	}
	row = i; col = j;
	while (row > 0 && col > 0)
	{
		if (arr[row][col] == 4 && row != i && col != j)//|| arr[row][col] == 1)
			return (0);
		row--;
		col--;
	}
	row = i; col = j;
	while (row < n && col < n)
	{
		if (arr[row][col] == 4 && row != i && col != j)//|| arr[row][col] == 1)
			return (0);
		row++;
		col++;
	}
	row = i; col = j;
	while (row > 0 && col < n)
	{
		if (arr[row][col] == 4 && row != i && col != j)//|| arr[row][col] == 1)
			return (0);
		row--;
		col++;
	}
	row = i; col = j;
	while (row < n && col > 0)
	{
		if (arr[row][col] == 4 && row != i && col != j)//|| arr[row][col] == 1)
			return (0);
		row++;
		col--;
	}
	return (1);
}

int valid (int **arr, int n)
{
	int i = 0;
	int j = 0;

	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (arr[i][j] == 4)
			{
				if (!ok(arr, n, i, j))
					return (0);
			}
			j++;
		}
		i ++;
	}
	return (1);
}

void	find_combination(int **arr, int n, int loc)
{
	if (loc == (n * n) - 1 && has_n_queens(arr, n))
	{
		if (has_n_queens(arr, n) && valid(arr, n))
			print_grid(arr, n);
		return;
	}
	// }
		int k = loc;
		while (k < (n * n))
		{
			//printf("loc: %d\n", loc);
			//print_grid(arr, n);
			int i = k/n;
			int j = k%n;
			if (usable(arr,n, i, j))
			{
				int a = arr[i][j];
				arr[i][j] = 4;
				mark_unusable(arr, n, i ,j);
				find_combination(arr, n, k + 1);
				arr[i][j] = a;
				mark_usable(arr, n, i , j);
			}
			k++;
		}

}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	write(1, argv[1], ft_strlen(argv[1]));
	write(1, "\n", 1);
	long n = ft_atoi(argv[1]);
	//printf("n: %ld\n", n);
	int **arr = make_grid(n);
	find_combination(arr, n, 0);	
	//print_grid(arr, n);
	//free_grid(arr, n);
}
