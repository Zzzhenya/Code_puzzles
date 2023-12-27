#include <stdio.h>
#include <stdlib.h>

void computer (char **str)
{
	
}


int main (void)
{
	FILE *fp;
	char str[1000][60];
	int i = 0;


	fp = fopen("input.txt", "r");
	while (1)
	{
		if (fgets (str[i], 60, fp))
		{
			puts(str[i]);
			i += 1;
		}
		else
			break;
	}
	fclose(fp);
	compute(str);
	return (0);
}