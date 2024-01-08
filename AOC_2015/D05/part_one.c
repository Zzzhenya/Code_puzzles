#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_three_vowels(char *line, ssize_t len)
{
	ssize_t i = 0;
	int check = 0;
	char charset[6] = "aeiuo";
	while (i < len)
	{
		if (strspn(&line[i], charset))
			check ++;
		i ++;
	}
	if (check >= 3)
		return (1);
	else
		return (0);
}

int check_reps(char *line, ssize_t len)
{
	ssize_t i = 0;
	while (i + 1 < len)
	{
		if (line[i] == line[i + 1])
			return (1);
		i ++;
	}
	return (0);

}

int check_combo(char *line, ssize_t len)
{
	ssize_t i = 0;
	while (i + 1 < len)
	{
		if (line[i] == 'a' && line[i + 1] == 'b')
			return (1);
		if (line[i] == 'c' && line[i + 1] == 'd')
			return (1);
		if (line[i] == 'p' && line[i + 1] == 'q')
			return (1);
		if (line[i] == 'x' && line[i + 1] == 'y')
			return (1);
		i ++;
	}
	return (0);

}

int reps_between(char *line, ssize_t len)
{
	ssize_t i = 0;
	while (i + 2 < len)
	{
		if (line[i] == line[i + 2] && line[i] != line [i + 1])
			return (1);
		i ++;
	}
	return (0);

}

int rep_pattern(char *line, ssize_t len)
{
	ssize_t i = 0;
	ssize_t j = 0;
	char a, b;

	while (i + 1 < len)
	{
		a = line[i];
		b = line[i + 1];
		j = i + 2;
		while (j + 1 < len)
		{
			if (line[j] == a && line[j + 1] == b)
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	ssize_t len = 0;
	int count = 0;
	int count2 = 0;
	FILE	*fp;

	if (argc != 2)
		return (0);
	fp = fopen(argv[1], "r");
	while ((linelen = getline(&line, &linecap, fp)) > 0)
	{
		if (check_three_vowels(line, linelen) && 
			check_reps(line, linelen) && !check_combo(line, linelen))
			count ++;
		if (reps_between(line, linelen) && rep_pattern(line, linelen))
			count2 ++;
	}
	printf("Count : %d\n", count);
	printf("Count2 : %d\n", count2);
	fclose(fp);
	return (0);
}