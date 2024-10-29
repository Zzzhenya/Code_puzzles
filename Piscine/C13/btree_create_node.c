#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	if (!item)
		return (NULL);
	t_btree  *t = malloc(sizeof(t_btree));
	if (!t)
		return (NULL);
	t->item = item;
	t->left = NULL;
	t->right = NULL;
	return(t);
}
/*
#include <stdio.h>
void	print_node(t_btree *node)
{
	if (!node)
		return;
	printf("%d l:%p r:%p\n", *(int*)(node->item), node->left, node->right);
}

int main (void)
{
	int *val = malloc(sizeof(int) * 1);
	*val = 5;

	t_btree *t = btree_create_node(NULL);
	print_node(t);
	free(t);
	t_btree *t2 = btree_create_node(val);
	print_node(t2);
	free(t2);
	free(val);

	return (0);
}*/
