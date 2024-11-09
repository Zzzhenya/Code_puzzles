#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/
*/

int ft_strlen(char *str)
{
	int len = 0;

	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

int combi_count(int n)
{
	int count = 1;
	int i = 0;
	while (i < n)
	{
		count = count * 2;
		i++;
	}
	return (count);
}

void	func(char *str, int len, int n, char arr[len+1], int k)
{
	static int i = 0;
	if (n == len)
	{
		printf("%d:\t%s\n",i, arr);
		return;
	}
	arr[k] = str[n];
	i++;
	func(str, len, n + 1, arr, k + 1);
	arr[k] = '\0';
	func(str, len, n + 1, arr, k);
}

void get_all_combi(char *str, int len)
{
	char arr[len+1];
	int i = 0;
	while (i <= len)
	{
		arr[i] = '\0';
		i++;
	}
	func(str, len, 0, arr, 0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Wrong arg count\n");
		return (1);
	}
	// remove repeats -> not done
	char *str = argv[1];
	int len = ft_strlen(str);
	int n = combi_count(len);
	printf("expected: %d\n", n);
	get_all_combi(str, len);
	return (0);
}
