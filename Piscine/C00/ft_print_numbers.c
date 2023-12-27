#include <unistd.h>

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void ft_print_numbers(void)
{
	int	i;

	i = '0';
	while (i <= '9')
	{
		ft_putchar ((char)i);
		i ++;
	}
}
/*
int main (void)
{
	ft_print_numbers();
	return (0);
}*/