#include <string.h>
#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	int status = 0;
	int i = 0;
	int j = 0;

	if (argc <= 1)
		return (status);
	while (argv[i])// && argv[++i])
	{
		i++;
		argv += i;
		i = 0;
		while(argv[i] && (strcmp(argv[i], ";") && strcmp(argv[i], "|")))
			i++;
		if (i) // this makes ; ; ; -> not go to the exec/printer loop
		{
			j = 0;
			while (j < i)
			{
				printf("%s\t", argv[j]);
				j ++;
			}
			printf("\n");
		}
	}
	return (status);
}