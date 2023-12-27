#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

typedef struct s_data
{
	int game;
	int try;
	int try_max;
	int green;
	int red;
 	int blue;
} t_data;

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

int get_try_size(char *line)
{
	char **try;
	int i = 0;

	try = ft_split(line, ';');
	while (try[i])
	{
		i ++;
	}
	free_arr(try);
	return (i);
}

void print_game(t_data *storage)
{
	int i = 0;
	int size = storage[0].try_max;
	//printf ("Game: %d\n", storage[0].game);
	while (i < size)
	{
		printf("try %d: r %d g %d b %d\n", 
			storage[i].try, 
			storage[i].red,
			storage[i].green,
			storage[i].blue);
		i ++;
	}
}

int compute(char *line, t_data *storage, int t)
{
	int i = 0;
	int check = 1;
	char **arr;
	char **try;
	char **num;
	int game = 0;
	int j = 0;
	int try_size;

	try_size = get_try_size(line);
	num = ft_split(line, ':');
	arr = ft_split(num[1], ';');
	free_arr(num);
	
	while (arr[i])
	{
		storage[i].game = t;
		storage[i].try = i + 1;
		storage[i].try_max = try_size;
		storage[i].red = 0;
		storage[i].green = 0;
		storage[i].blue = 0;
		try = ft_split(arr[i], ',');
		j = 0;
		while (try[j])
		{
			num = ft_split(try[j], ' ');
			if (*num[1] == 'b')
				storage[i].blue += ft_atoi(num[0]);
			else if (*num[1] == 'r')
				storage[i].red += ft_atoi(num[0]);
			else if (*num[1] == 'g')
				storage[i].green += ft_atoi(num[0]);
			free_arr(num);
			j ++;
		}
		if (storage[i].blue > 14)
			check = 0;
		if (storage[i].green > 13)
			check = 0;
		if (storage[i].red > 12)
			check = 0;
		free_arr(try);
		i ++;
	}
	//print_game(storage);
	free_arr(arr);
	if (check == 1)
		return (t);
	else
		return (check);
}

int compute_2(t_data *storage, int t, t_data coll)
{
	int i = 0;
	int size = storage[0].try_max;

	coll.red = 0;
	coll.green = 0;
	coll.blue = 0;

	while (i < size)
	{
		if (storage[i].red > coll.red)
			coll.red = storage[i].red;
		if (storage[i].green > coll.green)
			coll.green = storage[i].green;
		if (storage[i].blue > coll.blue)
			coll.blue = storage[i].blue;
		i ++;
	}
	return (coll.red * coll.green * coll.blue);
}

int main(int argc, char **argv)
{
	char *line;
	int fd;
	int total;
	int i = 0;
	int try_size;
	t_data *storage[100];
	t_data coll[100];

	total = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break;
			try_size = get_try_size(line);
			storage[i] = malloc(sizeof(t_data) * try_size);
			if (!storage[i])
				ft_errexit("Malloc failed");
			total += compute(line, storage[i], i + 1);
			free (line);
			i ++;
		}
		ft_printf("total: %d\n", total);
		close(fd);
		i = 0;
		total = 0;
		while (i < 100)
		{
			total += compute_2(storage[i], i, coll[i]);
			print_game(storage[i]);
			i ++;
		}
		ft_printf("total2: %d\n", total);
		i = 0;
		while (i < 100)
		{
			free(storage[i]);
			i ++;
		}
	}
	return (0);
}