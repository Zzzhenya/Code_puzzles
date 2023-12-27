#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

typedef struct s_data
{
	char c[4];
	int x1;
	int x2;
	int x3;
	int y;
	int size;
} t_data;

typedef struct s_num
{
	char c[4];
	int n;
	int dig;
} t_num;

void	free_arr(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i ++;
	}
	free(arr);
	arr = NULL;
}

int ft_issign(char c)
{
	if (!ft_isalpha(c) && c != '.')
		return (1);
	else
		return (0);
}

void	parse_and_store(char *line, t_data *rows, int  x)
{
	int i = 0;
	//int j = 0;

	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
		}
		else
		{
			printf("%c ", line[i]);
		}
		if (ft_issign(line[i]))
		{
			printf("%c: ", line[i]);
		}
		i ++;
	}
}


int main(int argc, char **argv)
{
	char 	*line;
	int 	fd;
	int 	i = 0;
	t_data 	*rows[1000];
	int 	char_size = 0;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break;
			rows[i] = malloc(sizeof(t_data) * 50);
			parse_and_store(line, rows[i], i);
			free (line);
			i ++;
		}
		ft_printf("char_size: %d\n", char_size);
		close(fd);
	}
	return (0);
}