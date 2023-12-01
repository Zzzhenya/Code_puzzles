#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int compute(char *line)
{
	int i = 0;
	char num[500];
	char *temp;
	int j = 0;
	int n;

	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			num[j] = line[i];
			j ++;
		}
		i ++;
	}
	num[j] = '\0';
	n = (num[0] - '0') * 10 + num[j - 1] - '0';
	return (n);
}

int main(int argc, char **argv)
{
	char *line;
	int fd;
	int total;
	int total2;

	total = 0;
	total2 = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break;
			total += compute(line);
			free (line);
		}
		printf("total: %d\n", total);
		close(fd);
	}
	return (0);
}