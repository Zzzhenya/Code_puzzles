#include <unistd.h>
/*
Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.*/

void	first_word(char *str)
{
	int i = 0;

	while (str[i] && (str[i] == '\t' || str[i] == ' '))
		i ++;
	while (str[i] && !(str[i] == '\t' && str[i] == ' '))
	{
		write (1, &str[i], 1);
		i ++;
	}
}


int main(int argc, char **argv)
{
	if (argc == 2)
		first_word(argv[1]);
	write (1, "\n", 1);
	return (0);
}