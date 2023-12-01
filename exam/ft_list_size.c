//#include <stdio.h>
#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	t_list *iter;
	int size;

	size = 0;
	if (!begin_list || begin_list == NULL)
		return (size);
	iter = begin_list;
	while (iter)
	{
		iter = iter->next;
		size ++;
	}
	return (size);
}
/*
int main(void)
{
	t_list *strt = NULL;
	t_list first;
	t_list second;

	printf("size: %d\n", ft_list_size(strt));
	first.next = NULL;
	first.data = (void *)4;
	printf("size: %d\n", ft_list_size(&first));
	second.data = (void *)10;
	second.next = NULL;
	first.next = &second;
	printf("size: %d\n", ft_list_size(&first));
}*/