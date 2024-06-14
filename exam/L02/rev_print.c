#include <unistd.h>
/*
Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.*/

int main (int argc, char **argv)
{
	int len = 0;

	if (argc == 2)
	{
		while (argv[1][len])
			len ++;
		while (len > 0)
		{
			write (1, &argv[1][len - 1], 1);
			len --;
		}
	}
	write (1, "\n", 1);
	return (0);
}