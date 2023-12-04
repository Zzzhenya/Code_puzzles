/*#include <string.h>
#include <stdlib.h>
#include <stdio.h>


Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);

 The strcpy() and strncpy() functions return dst.*/

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	if (!src)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main (void)
{
	char *dest;

	dest = malloc(sizeof(char) * 20);
	//dest = strcpy(dest, "Hello World!");
	dest = ft_strcpy(dest, "Hello World!");
	printf("%s\n", dest);
	return (0);
}*/