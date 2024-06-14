//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int main (void)
{
	int i = 10;
	int j = 25;

	printf("%d, %d\n", i, j);
	ft_swap(&i, &j);
	printf("%d, %d\n", i, j);
	return (0);
}*/