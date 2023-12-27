/*#include <stdio.h>*/
#include <unistd.h>

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len ++;
	return (len);

}
/*
int main (void)
{
	printf("len %d\n", ft_strlen("Hello World!"));
	return (0);
}*/