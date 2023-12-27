#include <stdio.h>

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	FILE	*fp;
	int i = 0;
	int floor = 0;
	int loc = 0;

	if (argc != 2)
		return (0);
	fp = fopen(argv[1], "r");
	linelen = getline(&line, &linecap, fp);
	while (line[i])
	{
		if (line[i] == '(')
			floor ++;
		else if (line[i] == ')')
			floor --;
		if (floor == -1 && loc == 0)
		{
			printf("first char loc: %d\n", i + 1);
			loc = 1;
		}
		i ++;
	}
	fclose(fp);
	printf("floors: %d\n", floor);
	return (0);
}