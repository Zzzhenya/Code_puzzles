/*

Knapsack Problem

Given N items where 
each item has some weight and profit associated with it

and also given a bag with capacity W, [i.e., the bag can hold at most W weight in it].

The task is to put the items into the bag such that 
the sum of profits associated with them is the maximum possible. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_item
{
	int weight;
	int price;
	int check;
} 				t_item;

int  calc_weight(t_item *arr, int size)
{
	int i = 0;
	int sum = 0;
	while (i < size)
	{
		if (arr[i].check == 1)
			sum += arr[i].weight;
		//printf("%d ", arr[i].weight);
		i++;
	}
	//printf("\n");
	return (sum);
}

int  calc_price(t_item *arr, int size)
{
	int i = 0;
	int sum = 0;
	while (i < size)
	{
		if (arr[i].check == 1)
			sum += arr[i].price;
		i++;
	}
	return (sum);
}

t_item *make_cpy(t_item *arr, int size)
{
	t_item *cpy = malloc(sizeof(t_item) * size);
	int i = 0;
	while ( i < size)
	{
		cpy[i].weight = arr[i].weight;
		cpy[i].price = arr[i].price;
		cpy[i].check = arr[i].check;
		i++;
	}
	return (cpy);
}

void print_path(t_item *arr, int size)
{
	int i = 0;
	while (i < size)
	{
		if (arr[i].check == 1)
			printf("(%d,%d) ", arr[i].weight, arr[i].price);
		i++;
	}

	printf("\t%d : %d\n", calc_weight(arr, size), calc_price(arr, size));
}

void print_arr(t_item *arr, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("%d ", arr[i].weight);
		i++;
	}
	printf("\n");
}

t_item *check_each(t_item *arr, int size, int sum, int loc)
{
	static int max = 0;
	static t_item *max_arr = NULL;

	if (!arr)
	{
		//printf("max: %d\n", max);
		return (max_arr);
	}
	else
	{
		if (calc_weight(arr, size) == sum)
		{
			//print_path(arr, size);
			if (calc_price(arr, size) > max)
			{
				max = calc_price(arr, size);
				if (max_arr)
					free (max_arr);
				max_arr = make_cpy(arr, size);
			}
			free (arr);
			return (NULL);
		}
		else
		{
			while (loc < size)
			{
				t_item *copy = make_cpy(arr, size);
				copy[loc].check = 1;
				check_each(copy, size, sum, loc + 1);
				loc++;
			}
		}
		return (NULL);
	}
}


int main(void)
{
	// char *line = NULL;
	// size_t linecap = 0;
	// ssize_t linelen;

	// while((linelen = getline(&line, &linecap, stdin)) > 0)
	// 	fwrite(line, linelen, 1, stdout);
	t_item arr[100];
	int len = 0;
	int sum;
	fscanf(stdin, "%d\n", &sum);
	int a;  int b;
	while (fscanf(stdin, "%d, %d\n", &a, &b) != EOF)
	{
		arr[len].weight = a;
		arr[len].price = b;
		arr[len].check = 0;
		len++;
	}
	t_item *cpy = make_cpy(arr, len);
	// print_arr(cpy, len);
	check_each(cpy, len, sum, 0);
	t_item *max = check_each(NULL, len, sum, 0);
	print_path(max, len);
	free(max);
	return (0);
}