/*
with puts write only
Write a program that will take as argument a string containing only parenthesis.
If parenthesis are unbalanced (for example "())") your program shall 
remove the minimum number of parenthesis for the pattern to be balanced.
remove = replace by spaces.
You will print all the solutions (can be more than one).
The order of the solutions is not important.
*/
#include <stdio.h>

#define L '('
#define R ')'
#define S '+' 

int ft_strlen(char *str)
{
	int len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return(len);
}

int order_weird(int len, char *str)
{
	int i = 0;
	int total = 0;
	int count = 0;

	while(i < len)
	{
		if (str[i] == L)
			total++;
		else if (str[i] == R)
		{
			if (total > 0)
				total--;
			else
				count++;
		}
		i++;
	}
	return (total+count);
}

int has_min_spaces(int len, char *str, int min)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == S)
			count++;
	}
	if (count == min)
		return (1);
	else
		return (0);
}


int i_not_in_arr(int idx, int min, int arr[min], int val)
{
	for (int i = 0; i < idx; i++)
	{
		if (arr[i] == val)
			return (0);
	}
	return (1);
}


int i_is_bigger(int idx, int min, int arr[min], int val)
{
	for (int i = 0; i < idx; i++)
	{
		if (arr[i] < val)
			return (0);
	}
	return (1);
}

void	print_combi(char *str, int len, int min, int arr[min], int idx)
{
	if (idx == min)
	{
		// reconstruct the string
		char cpy[len+1];
		cpy[len] = '\0';
		for (int i = 0; i < len; i++)
		{
			if (i_not_in_arr(min, min, arr, i))
				cpy[i] = str[i];
			else
				cpy[i] = S;
		}
		// print only if correct order
		if (!order_weird(len, cpy))
			puts(cpy);
		// for (int i = 0; i < min; i++)
		// 	printf("%d ", arr[i]);
		// printf("\n");
		return;
	}
	// Go through each letter
	int i = 0;
	while (i < len)
	{
		// check whether current combination is valid
		// don't continue if replacing index is repeated in the array
		// don't continue if new index is larger than already stored indices
		if (i_not_in_arr(idx, min, arr,  i) && i_is_bigger(idx, min, arr, i))
		{
			arr[idx] = i;
			// recurese for the next index
			print_combi(str, len, min, arr, idx + 1);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int len = ft_strlen(argv[1]);
	int min = order_weird(len, argv[1]);
	if (!min)
	{
		puts(argv[1]);
		return (0);
	}
	int arr[min];
	print_combi(argv[1], len, min, arr, 0);
	// for (int i = 0; i < len; i++)
	// 	arr[i] = 0;
	// modify(argv[1], len, min, arr, 0);
	return (0);
}