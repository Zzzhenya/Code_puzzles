#include <stdio.h>

#define SIZE 100

int main (void)
{
	//char str[SIZE];
	int k = 0;
	//for (int i = 0; i < SIZE; i++)
	//	str[i]='\0';
	char *str = NULL;
	int ret = fscanf(stdin, "%s", str);
	printf("%d: %d\t" , k,  ret);
        printf("%s\n" , str);
	k++;
	while (ret != EOF )//|| ret != -1)
	{
		ret = fscanf(stdin, "%s", str);
		if (ret !=EOF)
		{
			printf("%d: %d\t" , k,  ret);
			printf("%s\n" , str);
		}
		for (int i = 0; i < SIZE; i++)
                	str[i]='\0';
		k++;
	}
	return (0);
}
