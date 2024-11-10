#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

int no_repeats(int size, int arr[size], int idx, int val)
{
	for (int i = 0; i < idx; i++)
	{
		if (arr[i] == val)
			return (0);
	}
	return(1);
}

void print_string(char *str, int len, int size,int arr[size])
{
	for (int i = 0; i < len; i++)
		write (1, &str[arr[i]], 1);
	write (1, "\n", 1);
}

int sorted(char *str, int size)
{
	int i = 0;

	while (i + 1 < size)
	{
		if (str[i + 1] < str[i])
			return (0);
		i++;
	}
	return (1);
}

// Sort to make sure the startig string is in ASCII order
void sort_in_place(char *str, int size)
{
	while(!sorted(str, size))
	{
		int i = 0;
		while (i + 1 < size)
		{
			if (str[i] > str[i + 1])
			{
				char c = str[i];
				str[i] = str[i + 1];
				str[i + 1] = c;
			}
			i++;
		}
	}
}

void find_combi(char *str, int len, int size, int  arr[size], int idx)
{
	if (idx == size)
	{
		// for (int i = 0; i < size; i++)
		// 	printf("%d ", arr[i]);
		// printf("\n");
		print_string(str, len, size, arr);
		return;
	}
	int i = 0;
	while (i < len)
	{
		if (no_repeats(size, arr, idx, i))
		{
			arr[idx] = i;
			find_combi(str, len, size, arr, idx + 1);
		}
		i++; 
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int len = ft_strlen(argv[1]);
	sort_in_place(argv[1], len);
	int arr[len];
	find_combi(argv[1], len, len, arr, 0);
	return (0);
}
