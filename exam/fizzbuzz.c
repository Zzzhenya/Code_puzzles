#include <unistd.h>
/*
Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.*/

void	put_nbr(int n)
{
	char c;
	if (n < 10)
	{
		c = n + 48;
		write (1, &c, 1);
	}
	if (n > 9)
	{
		put_nbr(n/10);
		put_nbr(n%10);
	}
}

int main(void)
{
	int i = 1;

	while (i < 101)
	{
		if (!(i%3 || i%5))
			write (1, "fizzbuzz", 8);
		else if (!(i%3))
			write (1, "fizz", 4);
		else if (!(i%5))
			write (1, "buzz", 4);
		else
			put_nbr(i);
		write (1, "\n", 1);
		i ++;
	}
	return (0);
}
