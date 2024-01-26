/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Write a function that reverses (in-place) a string.

It must return its parameter.*/

int ft_strlen(char *str)
{
	int len = 0;

	if (!str)
		return (len);
	while (str[len])
		len ++;
	return (len);
}


char    *ft_strrev(char *str)
{
	int len = 0;
	int i = 0;
	char c;

	len = ft_strlen(str);
	while (i < len - 1)
	{
		c = str[i];
		str[i] = str[len - 1];
		str[len - 1] = c;
		i ++;
		len --;
	}
	return (str);
}
/*
int main (void)
{
	char *word;
	word = malloc (sizeof(char) * 13);
	word = memcpy(word, "Hello World!", 13);
	//char word[13] = "Hello World!";

	printf("%s\n", word);
	ft_strrev(word);
	printf("%s\n", word);
}*/