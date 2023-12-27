#include <unistd.h>

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n >= 0 || !n)
		ft_putchar ('P');
	else
		ft_putchar ('N');
}
/*
int main (void)
{
	ft_is_negative (10);
	ft_putchar('\n');
	ft_is_negative (-2);
	ft_putchar('\n');
	ft_is_negative (0);
	ft_putchar('\n');
	return (0);
}*/