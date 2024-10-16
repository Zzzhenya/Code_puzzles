/*
Place N queens on a NxN chess board so that
no two queens attack each other

*/
#include <unistd.h>

int ft_strlen(char *str)
{
	int len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return(len);
}

long ft_atoi(char *str)
{
	long long n = 0;
	int i = 0;
	long long sign = 1;
	char c;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		c = str[i] - '0';
		n = n * 10 + c;
		i++;
	}
	return (n * sign);
}

#include <stdio.h>

int **make_grid(int n)
{
	int i = 0;
	
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	write(1, argv[1], ft_strlen(argv[1]));
	write(1, "\n", 1);
	long n = ft_atoi(argv[1]);
	printf("n: %ld\n", n);
	int **arr = make_grid(n);
}