/*

Print all permutations of a given string(without repeated characters) 
- lexicographically pre-ordered and 
- lexicographically post-ordered and printed.
If there are repeat characters, duplicate permutations are printed.

https://www.geeksforgeeks.org/lexicographic-permutations-of-string/

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

int is_reverse_sorted(char *str, int size)
{
	int i = 0;

	while (i + 1 < size)
	{
		if (str[i + 1] > str[i])
			return (0);
		i++;
	}
	return (1);
}

// Sort to make sure the startig string is in ASCII order
void sort_in_place(char *str, int size, int loc)
{
	while(!sorted(str + loc, ft_strlen(str + loc)))
	{
		int i = loc;
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

int find_ceil(char *str, int size, int start)
{
	int i = start;
	i++;
	int min = str[i];
	int min_index = i;
	while (i < size)
	{
		if (str[i] > str[start] && str[i] < min )
		{
			min = str[i];
			min_index = i;
		}
		i++;
	}
	//printf("%c\n", str[min_index]);
	return (min_index);
}

int get_rightmost_smaller_than_next(char *str, int size)
{
	int i = size - 2;
	while (i >= 0)
	{
		if (str[i] < str[i + 1])
			return (i);
		i--;
	}
	return (i);
}

void	permute(char *str, int size)//, int loc)
{
	while (!is_reverse_sorted(str, size))
	{
		// print current permutation - if sorted its the first
		puts(str);
		// Find the rightmost character which is smaller than its next 
		// character. Let us call it 'first char'
		int i = get_rightmost_smaller_than_next(str, size);
		//printf("%c\n", str[i]);
		// If there is no such character, all are sorted in decreasing order, 
		// means we just printed the last permutation and we are done. 
		if ( i == -1 ) 
			break;
		else
		{ 
			// Find the ceil of 'first char' in right of first character. 
			// Ceil of a character is the smallest character greater than it 
			int ceil = find_ceil(str, size, i);
			//printf("%c\n", str[ceil]);
			// Swap first and second characters 
			char c = str[i];
			str[i] = str[ceil];
			str[ceil] = c;
			// Sort the string on right of 'first char' 
			sort_in_place(str, size, i + 1);
		} 
	}
	// prints the last permutation
	puts(str);
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
		sort_in_place(str, size, 0);
		//sort_in_place(str, size, 1);
		//puts(str);
		permute(str, size);//, 0);
	}
	return (0);
}
