#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

int fid_sol_count(int len)
{
	int i = 0;
	int ret = 1;
	while (i < len)
	{
		ret *= 2;
		i++;
	}
	return (ret);
}

void	print_arr(char *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		write (1, &arr[i], 1);
		write (1, " ", 1);
	}
	write (1, "\n", 1);
}

int no_repeats(char *str, int len)
{
	int i = 0;
	while (i < len)
	{
		int j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (0);
			j ++;
		}
		i++;
	}
	return (1);
}

void get_combi(char *str, int count, char *arr, int start)
{
	if (start == count  && no_repeats(arr, count))
	{
		print_arr(arr, count);
		return;
	}
	int i = start;
	while (i < ft_strlen(str))
	{
		arr[start] = str[i];
		get_combi(str, count, arr, start + 1);
		i++;
	}
}



void superset(char *str, int n)
{
	// print empty set
	write (1, "", 1);
	write (1, "\n", 1);
	int i = 0;
	while (i < n - 1)
	{
		char *arr = malloc(sizeof(char) * (i + 1));
		get_combi(str, i + 1, arr, 0);
		free(arr);
		i++;
	}
}


int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	//char *str = find_set(argv[1]);
	int len = ft_strlen(argv[1]);
	int n = fid_sol_count(len);
	printf("%s : %d\n", argv[1], n);
	superset(argv[1], n);
	return (0);
}