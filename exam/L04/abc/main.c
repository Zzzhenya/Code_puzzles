#include <stdio.h>
#include <stdlib.h>

int get_num_count(char **argv)
{
	int len = 0;
	while (argv[len])
		len++;
	return (len);
}

int no_repeats(int len, int arr[len], int size, int idx_arr[size], int val)
{
	int i = 0;
	while (i < size)
	{
		if (idx_arr[i] == val)
			return (0);
		i ++;
	}
	return (1);
}

void	get_combi( int len, int arr[len], int size, int idx_arr[size], int idx)
{
	if (idx == size)
	{
		// int new_sum = 0;
		// for (int i = 0; i < size; i++)
		// 	new_sum += arr[idx_arr[i]];
		//if (new_sum == sum)
		{
			//for (int i = 0; i < size; i++)
				//printf("%d ", arr[idx_arr[i]]);
			for (int i = 0; i < size; i++)
				printf("%d ", idx_arr[i]);
			printf("\n");
		}
		return;
	}
	int i = 0;
	while (i <= len)
	{
		//if (no_repeats(len, arr, size, idx_arr, i))
		{
			idx_arr[idx] = i;
			get_combi( len, arr, size, idx_arr, idx + 1);
		}
		i++;
	}
}


void	find_combi(int len, int arr[len])
{
	int i = 0;
	while (i <= len)
	{
		int idx_arr[i];
		for (int j = 0; j <)
		get_combi(len, arr, i, idx_arr, 0);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	// int sum = atoi(argv[1]);
	int count = get_num_count(argv + 1 );
	int arr[count];
	for(int i = 0; i < count; i++)
		arr[i] = atoi(argv[i + 1]);
	find_combi(count, arr);
//	for (int i = 0; i < count; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
	return (0);
}
