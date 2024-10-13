/*

Print all permutations of a given string(with repeated characters)
int ASCII order.
Duplicate permutations resulting from repeat characters are not printed.
Resulting list of permutations are considered a set.


https://www.geeksforgeeks.org/print-all-permutations-of-a-string-with-duplicates-allowed-in-input-string/


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
		// backtracking
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
	// if string is empty does not print anything
	if (size)
	{
		sort_in_place(str, size);
		//puts(str);
		permute(str, size, 0);
	}
	return (0);
}