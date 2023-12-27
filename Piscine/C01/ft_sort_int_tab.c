/*#include <stdio.h>*/

static void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int ft_sorted(int *tab, int size)
{
	int i;

	i = 0;
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i ++;
	}
	return (1);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	while (!ft_sorted(tab, size))
	{
		i = 0;
		while (i + 1 < size)
		{
			if (tab[i] > tab[i + 1])
				ft_swap(&tab[i], &tab[i + 1]);
			i ++;
		}
	}
}
/*
int main (void)
{
	int tab[7] = {100, 2, 3,89, 2, 6, 6};
	int i = 0;


	while (i < 7)
	{
		printf("%d ", tab[i]);
		i ++;
	}
	printf("\n");
	ft_sort_int_tab(tab, 7);
	i = 0;
	while (i < 7)
	{
		printf("%d ", tab[i]);
		i ++;
	}
	printf("\n");
	return (0);
}*/