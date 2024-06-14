//#include <stdio.h>

void print_tab(int *tab,unsigned int size)
{
	int i = 0;
	while (i < size)
	{
		printf("%d, ", tab[i]);
		i ++;
	}
	printf("\n");
}

void sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int temp;
	
	if (size == 1 || size == 0)
		return;
	while (i < size - 1)
	{
		if (tab[i] > tab [i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i ++;
	}
}
/*
int main (void)
{
	unsigned int size = 10;
	int tab[10] = {4, 3, 12, 643, 2, 9, 2, 2, 54, 0};

	print_tab(tab, size);
	sort_int_tab(tab, size);
	print_tab(tab, size);
	return (0);
}*/