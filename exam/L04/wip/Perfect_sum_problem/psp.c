/*
Perfect Sum Problem (Print all subsets with given sum)

Given an array of integers and a sum, 
the task is to print all subsets of the 
given array with a sum equal to a given sum.
*/
// #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_sum
{
	int val;
	int check;
	char *str;
} 				t_sum;

size_t ft_strlen(char *str)
{
	size_t len = 0;

	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

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

t_sum *get_array(char **arr, int size)
{
	t_sum *int_arr = malloc(sizeof(t_sum) * size);
	int i = 0;
	while (i < size)
	{
		int_arr[i].val = ft_atoi(arr[i]);
		int_arr[i].check = 0;
		int_arr[i].str = arr[i];
		i++;
	}
	return (int_arr);
}

int get_sum(t_sum *arr, int size)
{
	int i = 0;
	int sum = 0;
	while (i < size)
	{
		if (arr[i].check == 1)
			sum += arr[i].val;
		i++;
	}
	return (sum);
}

void	print_arr(t_sum *arr, int size)
{
	int i = 0;
	while (i < size)
	{
		//printf("%d ", arr[i].val);
		write (1, arr[i].str, ft_strlen(arr[i].str));
		write (1, " ", 1);
		i++;
	}
	write (1, "\n", 1);
}

void	print_path(t_sum *arr, int size)
{
	int i = 0;
	int count = 0;
	while (i < size)
	{
		if (arr[i].check == 1)
		{
			write (1, arr[i].str, ft_strlen(arr[i].str));
			write (1, " ", 1);
			count++;
		}
		i++;
	}
	if (count)
		write (1, "\n", 1);
	// else
	// 	write (1, "Nothing\n", 8);
}

t_sum *make_copy(t_sum *arr, int size)
{
	t_sum *copy = malloc(sizeof(t_sum) * size);
	int i = 0;
	while (i < size)
	{
		copy[i].val = arr[i].val;
		copy[i].check = arr[i].check;
		copy[i].str = arr[i].str;
		i++;
	}
	return (copy);
}

void find_and_print(t_sum *arr, int size, int loc, int target)
{
	if (get_sum(arr, size) >= target || loc >= size - 1)
	{
		if (get_sum(arr, size) == target)
			print_path(arr, size);
		free(arr);
		return;
	}
	else
	{
		while (loc < size)
		{
			t_sum *copy = make_copy(arr, size);
			copy[loc].check = 1;
			if (loc < size)
				find_and_print(copy, size, loc + 1, target);
			loc++;
		}
	}
}

/*
convert sum to int
convert char **arr to int **arr
write perfect sum algo
print combination - recursion
	print strs
*/
int main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	t_sum *arr = get_array(argv + 2, argc - 2);
	find_and_print(arr, argc - 1, 0, ft_atoi(argv[1]));

	return (0);
}