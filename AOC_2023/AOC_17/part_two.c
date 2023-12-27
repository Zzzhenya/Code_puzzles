#include "../libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

typedef struct s_data
{
	char	dir;
	ssize_t mag;
} t_data;

typedef struct s_lace
{
	ssize_t x;
	ssize_t y;
	int in;
}	t_lace;

int count_lines(char *file)
{
	int fd;
	char *line;
	int line_count;

	line = NULL;
	line_count = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_count ++;
		free (line);
	}
	close (fd);
	return (line_count);
}

static void	free_arr(char **arr)
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

void print_data(t_data *data, int lines)
{
	int i;

	i = 0;
	while (i < lines)
	{
		ft_printf("%c : %d \n", data[i].dir, data[i].mag);
		i ++;
	}
}

ssize_t convert_hexa(char *str)
{
	int i = 4;
	ssize_t num = 0;
	int mult = 1;
	while (i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
			num += (str[i] - '0') * mult;
		else
			num += ((str[i] - 'a') + 10 ) * mult;
		mult *= 16;
		i --;
	}
	return (num);
}

t_data *store_data(char *file, t_data *data, int lines)
{
	int fd;
	char *line;
	char **arr;
	char *hexa;
	int i;

	line = NULL;
	i = 0;
	data = malloc(sizeof(t_data) * (lines));
	fd = open (file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		arr = ft_split(line, ' ');
		hexa = malloc(sizeof(char) * 6);
		if (arr[2][7] == '0')
			data[i].dir = 'R';
		else if (arr[2][7] == '2')
			data[i].dir = 'L';
		else if (arr[2][7] == '1')
			data[i].dir = 'D';
		else if (arr[2][7] == '3')
			data[i].dir = 'U';
		hexa[0] = arr[2][2];
		hexa[1] = arr[2][3];
		hexa[2] = arr[2][4];
		hexa[3] = arr[2][5];
		hexa[4] = arr[2][6];
		hexa[5] = '\0';
		data[i].mag = convert_hexa(hexa);
		i ++;
		free (hexa);
		free (arr);
		free (line);
	}
	return (data);
}

t_lace *store_cords(t_data *data, int lines)
{
	int i = 0;
	ssize_t x = 0;
	ssize_t y = 0;
	t_lace *arr;

	arr = malloc(sizeof(t_lace) * lines + 1);
	arr[i].in = i;
	arr[i].x = 0;
	arr[i].y = 0;
	i ++;
	while (i < lines)
	{
		if (data[i].dir == 'R') // R
			x += data[i].mag;
		else if (data[i].dir == 'L') //L
			x -= data[i].mag;
		else if (data[i].dir == 'D') //D
			y += data[i].mag;
		else if (data[i].dir == 'U') //U
			y -= data[i].mag;
		arr[i].in = i;
		arr[i].x = x;
		arr[i].y = y;
		i ++;
	}
	return (arr);
}

ssize_t shoelace_algo(t_lace *arr, int lines)
{
	int i = 0;
	ssize_t xayb = 0;
	ssize_t yaxb = 0;

	while (i < lines)
	{
		xayb += arr[i].x * arr[i + 1].y;
		yaxb += arr[i].y * arr[i + 1].x;
 		i ++;
	}
	return (labs(xayb - yaxb) / 2);
}

ssize_t line_len(t_data *data, int lines)
{
	int i = 0;
	ssize_t len = 0;

	while (i < lines)
	{
		len += data[i].mag;
		i ++;
	}
	return (len);
}

int main(int ac, char **av)
{
	t_data	*data;
	int 	lines;
	ssize_t 	len;
	ssize_t 	area;
	t_lace 	*arr;

	lines = 0;
	if (ac == 2)
	{
		lines = count_lines(av[1]);
		data  = store_data(av[1], data, lines);
		ft_printf("number of lines: %d\n", lines);
		len = line_len(data, lines);
		printf("len: %zd\n", len);
		arr = store_cords(data, lines);
		area = shoelace_algo(arr, lines);
		printf("area = %zd\n", area + (len)/2 + 1);
		free (data);
		free (arr);
		data = NULL;
		arr = NULL;
	}
	return (0);
}