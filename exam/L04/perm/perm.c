/*

Print all permutations of a given string(without repeated characters)
int ASCII order.
If there are repeat characters, duplicate permutations are printed.

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

// Sort to make sure the startig string is in ASCII order
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
	static int term = 0;
	if (loc == size - 1)
	{
		puts(str);
		return;
	}
	int i = loc;
	term ++;
	while (i < size)
	{
		char c = str[i];
		str[i] = str[loc];
		str[loc] = c;
		printf("%d permute loc:%d i:%d str[loc]:%c str[i]:%c\t %s\n", term, loc + 1, i, str[loc], str[i], str);
		permute(str, size, loc + 1);
		// backtracking
		c = str[i];
		str[i] = str[loc];
		str[loc] = c;
		printf("%d loop loc:%d i:%d str[loc]:%c str[i]:%c\t %s\n", term, loc + 1, i, str[loc], str[i], str);
		i++;
	}

}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	char *str = argv[1];
	int size = ft_strlen(str);
	// if string is empty does not print anything
	if (size)
	{
		sort_in_place(str, size);
		//puts(str);
		permute(str, size, 0);
	}
	return (0);
}