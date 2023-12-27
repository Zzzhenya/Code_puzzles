/*#include <stdio.h>
 
This function divides parameters a by b. 
The result of this division is stored in the
int pointed by a. 
The remainder of the division is stored in 
the int pointed by b.*/

void	ft_div_mod(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = temp / *b;
	*b = temp % *b;

}
/*
int main (void)
{
	int a, b;

	a = 10;
	b = 5;
	printf("%d by %d = ", a, b);
	ft_div_mod(&a, &b);
	printf("div %d, mod %d\n", a, b);
	return (0);
}*/