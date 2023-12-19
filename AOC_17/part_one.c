#include "../libft/libft.h"
#include <fcntl.h>
#include <math.h>

typedef struct s_data
{
	char dir;
	int mag;
} t_data;

typedef struct s_lace
{
	int x;
	int y;
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

t_data *store_data(char *file, t_data *data, int lines)
{
	int fd;
	char *line;
	char **arr;
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
		data[i].dir = *arr[0];
		data[i].mag = ft_atoi(arr[1]);
		i ++;
		free (arr);
		free (line);
	}
	return (data);
}

t_lace *store_cords(t_data *data, int lines)
{
	int i = 0;
	int x = 0;
	int y = 0;
	t_lace *arr;

	arr = malloc(sizeof(t_lace) * lines + 1);
	arr[i].in = i;
	arr[i].x = 0;
	arr[i].y = 0;
	i ++;
	while (i < lines)
	{
		if (data[i].dir == 'R') 
			x += data[i].mag;
		else if (data[i].dir == 'L')
			x -= data[i].mag;
		else if (data[i].dir == 'D')
			y += data[i].mag;
		else if (data[i].dir == 'U')
			y -= data[i].mag;
		arr[i].in = i;
		arr[i].x = x;
		arr[i].y = y;
		i ++;
	}
	return (arr);
}

int shoelace_algo(t_lace *arr, int lines)
{
	int i = 0;
	int xayb = 0;
	int yaxb = 0;

	while (i < lines)
	{
		xayb += arr[i].x * arr[i + 1].y;
		yaxb += arr[i].y * arr[i + 1].x;
 		i ++;
	}
	return (abs(xayb - yaxb) / 2);
}

int line_len(t_data *data, int lines)
{
	int i = 0;
	int len = 0;

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
	int 	len;
	int 	area;
	t_lace 	*arr;

	lines = 0;
	if (ac == 2)
	{
		lines = count_lines(av[1]);
		data  = store_data(av[1], data, lines);
		ft_printf("number of lines: %d\n", lines);
		len = line_len(data, lines);
		ft_printf("len: %d\n", len);
		arr = store_cords(data, lines);
		area = shoelace_algo(arr, lines);
		ft_printf("area = %d\n", area + (len)/2 + 1);
		free (data);
		free (arr);
		data = NULL;
		arr = NULL;
	}
	return (0);
}