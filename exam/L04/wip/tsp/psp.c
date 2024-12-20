/*
Perfect Sum Problem (Print all subsets with given sum)

Given an array of integers and a sum, 
the task is to print all subsets of the 
given array with a sum equal to a given sum.
*/
#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
	int n = 0;
	int i = 0;
	char c;
	int sign = 1;

	if (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		c = str[i] - 48;
		n = (n * 10) + c;
		i++;
	}
	return (n * sign);
}

int *get_array(char **arr, int size)
{
	int *int_arr = malloc(sizeof(int) * size);
	int i = 0;
	while (i < size)
	{
		int_arr[i] = ft_atoi(arr[i]);
		i++;
	}
	return (int_arr);
}

void	print_arr(int *arr, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
}

// convert sum to int
// convert char **arr to int **arr
// write perfect sum algo
// print combination
	// convert int to char *str 
	// print strs
int main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	// char *sum = argv[1];
	// char **arr = argv + 1;

	//int sum = ft_atoi(argv[1]);
	int *arr = get_array(argv + 1, argc - 1);
	print_arr(arr, argc - 1);

	return (0);
}