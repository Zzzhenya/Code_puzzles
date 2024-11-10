#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// void	print_arr(int len, int arr[len])
// {
// 	for (int i = 0; i < len; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// }

int not_a_repeat(int size, int arr[size], int val)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == val)
			return (0);
	}
	return (1);
}

int not_reverse(int size, int arr[size], int val)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > val)
			return (0);
	}
	return (1);
}

void print_set(int size, int num[size], int len, int arr[len], int sum)
{
	int total = 0;
	for (int i = 0; i < len; i++)
		total += num[arr[i]];
	if (total == sum)
	{
		for (int i = 0; i < len; i++)	
			printf("%d ", num[arr[i]]);
		printf("\n");
	}
	else
		return;
	
}

void	get_combi(int size, int num[size], int len, int arr[len], int idx, int sum)
{
	if (idx == len)
	{
		// print_arr(len, arr);
		print_set(size, num, len, arr, sum);
		return;
	}
	int i = 0;
	while (i < size)
	{
		if (not_a_repeat(idx, arr,i) && not_reverse(idx, arr, i))
		{
			arr[idx] = i;
			get_combi(size, num, len, arr, idx + 1, sum);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("./a.out <sum> <val1> <val2> ...\n");
		return (1);
	}
	int sum = atoi(argv[1]);
	int size = argc - 2;
	int num[size];
	for (int i = 0; i < size; i++)
		num[i] = atoi(argv[i + 2]);
	int i = 0;
	while (i <= size)
	{
		int arr[i];
		get_combi(size, num, i, arr, 0, sum);
		i++;
	}
	// for (int i = 0; i < size; i++)
	// 	printf("%d\n", arr[i]);
	return (0);
}