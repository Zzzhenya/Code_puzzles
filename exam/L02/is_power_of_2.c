/*
#include <stdio.h>
Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, 
otherwise it returns 0.

*/
int	    is_power_of_2(unsigned int n)
{
	int i;

	i = n;
	while (i > 1 && !(i%2))
	{
		i = i/2;
	}
	if (i == 1)
		return (1);
	else
		return (0);
}
/*
int main(void)
{
	if (is_power_of_2(0))
		printf("is power of two\n");
	return(0);
}*/