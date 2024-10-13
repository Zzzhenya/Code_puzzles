/*

Print all permutations of a givern string

https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

A string of length N has N! permutations
*/
#include <stdio.h>

int ft_strlen(char *str)
{
	int len  = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
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

void sort_in_place(char *str, int size)
{
	if (sorted(str, size))
		return;
	else
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
		sort_in_place(str, size);
	}
}

void	permute(char *str, int size, int loc)
{
	if (loc == size - 1)
	{
		puts(str);
		return;
	}
	int i = loc;
	while (i < size)
	{
		char c = str[i];
		str[i] = str[loc];
		str[loc] = c;
		permute(str, size, loc + 1);
		c = str[i];
		str[i] = str[loc];
		str[loc] = c;
		i++;
	}

}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	char *str = argv[1];
	int size = ft_strlen(str);
	if (size)
	{
		sort_in_place(str, size);
		//puts(str);
		permute(str, size, 0);
	}
	return (0);
}