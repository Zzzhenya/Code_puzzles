#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int *ptr = malloc(sizeof(int) * 1);

	*ptr = 100;
	printf("%d\n", *ptr);
	ptr = realloc(ptr, sizeof(int)*2);
	//ptr[0] = 9;
	ptr[1] = 200;
	printf("%d %d\n", *ptr, ptr[1]);
	ptr = realloc(ptr, sizeof(int)*3);
	//ptr[2] = 900;
	printf("%d %d %d\n", *ptr, ptr[1], ptr[2]);
	return (0);
}