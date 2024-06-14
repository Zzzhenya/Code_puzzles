#include <stdlib.h>
/*
#include <string.h>
#include <stdio.h>*/

int ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (i);
	while (str[i])
		i ++;
	return(i);
}

char    *ft_strdup(char *src)
{
	char *copy;
	int len;
	int i;

	i = 0;
	len = ft_strlen(src);
	copy = malloc(sizeof(char) *ft_strlen(src) + 1);
	if (!copy)
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i ++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
int main(void)
{
	char *str;

	str = ft_strdup("jsahflhfashfshfisAHFOIASHFIASPHF");
	printf("%s\n", str);
	return (0);
}*/