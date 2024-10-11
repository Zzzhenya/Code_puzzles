#include <unistd.h>
// #include <stdio.h>
#include <stdlib.h>

/*

Expected files: *.c *.h
Allowed functions: puts, write
Write a program that will take as argument a string containing only parenthesis.
If parenthesis are unbalanced (for example "())") your program shall 
remove the minimum number of parenthesis for the expression to be balanced.
By removing we mean replacing by spaces.
You will print all the solutions (can be more than one).
The order of the solutions is not important.
For example this should work:
(For readability reasons the '_' means space and the spaces are for readability only.)
$> ./rip '( ( )' | cat -e
_ ( ) $
( _ ) $
$> ./rip '( ( ( ) ( ) ( ) ) ( ) )' | cat -e
( ( ( ) ( ) ( ) ) ( ) ) $
$> ./rip '( ) ( ) ) ( )' | cat -e
( ) ( ) _ ( ) $
( ) ( _ ) ( ) $
( _ ( ) ) ( ) $
$> ./rip '( ( ) ( ( ) (' | cat -e
( ( ) _ _ ) _ $
( _ ) ( _ ) _ $
( _ ) _ ( ) _ $
_ ( ) ( _ ) _ $
_ ( ) _ ( ) _ $

*/

size_t ft_strlen(char *str)
{
	size_t len = 0;

	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

int arr_is_weird(char *arr, int size)
{
	int i = 0;

	int min = 0;
	int total = 0;

	if (!arr)
		return (0);
	while (i < size)
	{
		if (arr[i] == ']' && total > 0)
			total--;
		else if (arr[i] == ']' && total <= 0)
			min++;
		else if (arr[i] == '[' )
			total++;
		i++;
	}
	if (min + total)
		return (1);
	else
		return (0);
}

char *copy_str(char *arr, int size)
{
	char *new = malloc(sizeof(char) * (size + 1));
	int i = 0;
	while (i <= size)
	{
		new[i] = arr[i];
		i++;
	}
	return (new);
}

int find_extra(char *arr, int size)
{
	int i = 0;

	int min = 0;
	int total = 0;

	while (i < size)
	{
		if (arr[i] == ']' && total > 0)
			total--;
		else if (arr[i] == ']' && total <= 0)
			min++;
		else if (arr[i] == '[' )
			total++;
		i++;
	}
	return (min + total);
}

int find_min_mod(char *arr, int size)
{
	char *copy = copy_str(arr, size);

	int min = find_extra(copy, size);
	free(copy);
	return (min);
}

int right_space_count(char *arr, int size, int num)
{
	int i = 0;

	while (i < size)
	{
		if (arr[i] == '_')
			num--;
		i++;
	}
	if (num == 0)
		return (1);
	else
		return (0);
}

void print_arr(char *str, int size)
{
	int i = 0;

	while (i < size)
	{
		write (1, &str[i], 1);
		// if (i < size - 1)
			write (1, " " , 1);
		// else
		// 	write (1, "\n" , 1);
		i++;
	}
}

void print_all_variations(char *arr, int size, int num, int start, int next)
{
	if (right_space_count(arr, size, num))
	{
		if (!arr_is_weird(arr, size))
			print_arr(arr, size);
		free (arr);
		return;
	}
	else
	{
		while (next < size)
		{
			char *copy = copy_str(arr, size);
			copy[next] = '_';
    		if (next < size)
				print_all_variations(copy, size, num, start, next + 1);
			next++;
		}
	}
}

void process_arr(char *arr, int size)
{
	int min_mod = find_min_mod(arr, size);

	// printf("min_mod %d\n", min_mod);
	int start = 0;
	while (start <= size - min_mod)
	{
		char *copy = copy_str(arr, size);
		copy[start] = '_';
		print_all_variations(copy, size, min_mod, start, start + 1);
		//free(copy);
		start ++;
	}
	
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int size = ft_strlen(argv[1]);

	print_arr(argv[1], size);
	write (1, "\n", 1);
	// printf("%s \t:%d\n", argv[1], size);

	if (arr_is_weird(argv[1], size))
		process_arr(argv[1], size);
	return (0);
}