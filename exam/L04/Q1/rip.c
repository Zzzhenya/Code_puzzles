#include <stdio.h>

#define L '('
#define R ')'
#define S '_'

int ft_strlen(char *str)
{
	int len = 0;
	if (!str)
		return (len);
	while (str[len]!= '\0')
		len++;
	return (len);
}

int order_werid(int len, char *str)
{
	int r = 0;
	int l = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == L)
			l++;
		else if (str[i] == R)
		{
			if (l > 0)
				l--;
			else
				r++;
		}
	}
	return (l + r);
}

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

// void	print_arr(int size, int arr[size])
// {
// 	for (int i = 0; i < size; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// }

void	print_string(char *str, int len, int size, int arr[size])
{
	char cpy[len + 1];
	int j = 0;

	cpy[len] = '\0';
	for (int i = 0; i < len; i++)
	{
		if (j < size && arr[j] == i)
		{
			cpy[i] = S;
			j++;
		}
		else
			cpy[i] = str[i];
	}
	if (!order_werid(len, cpy))
		puts(cpy);
}


void	print_combi(char *str, int len, int size, int arr[size], int idx)
{
	if (idx == size)
	{
		//print_arr(size, arr);
		print_string(str, len, size, arr);
		return;
	}
	int i = 0;
	while (i < len)
	{
		if (not_a_repeat(idx, arr, i) && not_reverse(idx, arr, i))
		{
			arr[idx] = i;
			print_combi(str, len, size, arr, idx + 1);
		}
		i++;
	}
}

int main (int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int len = ft_strlen(argv[1]);
	int min_changes = order_werid(len, argv[1]);
	if (!min_changes)
	{
		puts(argv[1]);
		return (0);
	}
	int arr[min_changes];
	print_combi(argv[1], len, min_changes, arr, 0);
}