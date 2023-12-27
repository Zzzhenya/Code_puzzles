/*#include <stdio.h>*/

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i ++;
	}
}
/*
int main (void)
{
	int tab[2] = {1,2};
	int i = 0;


	while (i < 2)
	{
		printf("%d ", tab[i]);
		i ++;
	}
	printf("\n");
	ft_rev_int_tab(tab, 2);
	i = 0;
	while (i < 2)
	{
		printf("%d ", tab[i]);
		i ++;
	}
	printf("\n");
	return (0);
}*/