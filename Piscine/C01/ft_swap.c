/*#include <stdio.h>
 Create a function that swaps 
the value of two integers whose addresses are entered
as parameters.*/

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int main(void)
{
	int a = 12;
	int b = 24;

	printf("a: %d, b: %d\n", a, b);
	ft_swap (&a, &b);
	printf("a: %d, b: %d\n", a, b);
	return (0);
}*/