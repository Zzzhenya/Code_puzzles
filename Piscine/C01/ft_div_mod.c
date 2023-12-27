/*#include <stdio.h>

This function 
divides parameters a by b 
and stores the result in the int pointed by div. 
It also stores the remainder of the division 
of a by b in the int pointed by mod.
*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a/b;
	*mod = a%b;

}
/*
int main (void)
{
	int a, b;
	int div, mod;

	a = 129;
	b = 5;
	div = 0;
	mod = 0;
	printf("%d by %d = div %d, mod %d\n", a, b, div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("%d by %d = div %d, mod %d\n", a, b, div, mod);
	return (0);
}*/