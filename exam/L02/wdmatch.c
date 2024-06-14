#include <unistd.h>
/*
Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.*/
int ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while (str[i])
		i ++;
	return (i);
}

int wdmatch(char *needle, char *haystack)
{
	int i = 0;
	int j= 0;

	while (haystack[i] && needle[j])
	{
		if (haystack[i] == needle[j])
			j ++;
		i ++;
	}
	if (needle[j] == '\0')
		return (1);
	else
		return(0);
}


int main (int argc, char **argv)
{
	if (argc == 3)
	{
		if (wdmatch(argv[1], argv[2]))
			write (1, argv[1], ft_strlen(argv[1]));
	}
	write (1, "\n", 1);
	return(0);
}