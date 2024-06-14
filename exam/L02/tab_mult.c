#include <unistd.h>
/*
Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.
*/

void	ft_putnbr(int nbr)
{
	int n = nbr;
	char c;

	if (n < 10)
	{
		c = n + '0';
		write (1, &c, 1);
	}
	if (n > 9)
	{
		ft_putnbr(n/10);
		ft_putnbr(n%10);
	}
}

int str_to_nbr(char *str)
{
	int i = 0;
	int n = 0;;

	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i ++;
	}
	return (n);
}

int main(int argc, char **argv)
{
	int n;
	int i = 1;
	char c;

	if (argc == 2)
	{
		n = str_to_nbr(argv[1]);
		while (i < 10)
		{
			c = (char)(i + '0');
			write (1, &c, 1);
			write (1, " x ", 3);
			ft_putnbr(n);
			write (1, " = ", 3);
			ft_putnbr(n * i);
			write (1, "\n", 1);
			i ++;
		}
	}
	else
		write (1, "\n", 1);
	return (0);
}