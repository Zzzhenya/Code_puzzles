#include <unistd.h>

static int get_len(char *str)
{
	int len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len ++;
	return (len);

}

void	ft_putstr(char *str)
{
	int len;

	len = 0;
	len = get_len(str);
	write (1, str, len);
}
/*
int main (void)
{
	ft_putstr("Hello World!");
	return (0);
}*/