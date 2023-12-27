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

/*
void print_game(t_data *storage)
{

}*/
/*
int  get_char_size(char *line)
{
	int i = 0;
	char **num;

	num = ft_split(line, '.');
	while (num[i])
		i ++;
	free_arr(num);
	return (i);
}*/

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

			//printf("%c ", line[i]);
			//collect digits
		}
		else
		{
			//printf("%c ", line[i-3]);
			//printf("%c ", line[i-2]);
			//printf("%c ", line[i-1]);
			printf("%c ", line[i]);
		}
		if (ft_issign(line[i]))
		{
			printf("%c: ", line[i]);
		}
		/*
		else 

			if there are digits
				store it as a t_data
				{
					1-2 chars;
					atoi
					number of chars;
					x1, x2, x3
					y
				}
				icrement t_data * iter
			if (ft_issign(line[i]))
			{
				store the char as a t_data
				{
					1 char;
					number of chars;
					x1
					y
				}
				icrement t_data * iter
			}*/
		i ++;
	}
}


int main(int argc, char **argv)
{
	char 	*line;
	int 	fd;
	//int 	total = 0;
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
		//total = compute (rows);
		ft_printf("char_size: %d\n", char_size);
		close(fd);
		/*
		i = 0;
		while (i < 100)
		{
			free(rows[i]);
			i ++;
		}*/
	}
	return (0);
}