/*

Knapsack Problem

Given N items where 
each item has some weight and profit associated with it

and also given a bag with capacity W, [i.e., the bag can hold at most W weight in it].

The task is to put the items into the bag such that 
the sum of profits associated with them is the maximum possible. 
*/

#include <stdio.h>

int main(void)
{
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;

	while((linelen = getline(&line, &linecap, stdin)) > 0)
		fwrite(line, linelen, 1, stdout);
	return (0);
}