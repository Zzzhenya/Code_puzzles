#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_lims
{
	int x_min;
	int y_min;
	int x_max;
	int y_max;
	int w;
	int h;
}	t_lims;	

void get_lims(char *line, t_lims *lims, int i)
{
	int x = 0;
	int y = 0;

	while (line[i])
	{
		if (line[i] == '>')
			x += 1;
		else if (line[i] == '<')
			x -= 1;
		else if (line[i] == '^')
			y += 1;
		else if (line[i] == 'v')
			y -= 1;
		if (x > lims->x_max)
			lims->x_max = x;
		if (x < lims->x_min)
			lims->x_min = x;
		if (y > lims->y_max)
			lims->y_max = y;
		if (y < lims->y_min)
			lims->y_min = y;
		i += 2;
	}
}

void mark_cords(char *str, t_lims *lims, int *arr, int i)
{
	int size = lims->h * lims->w;
	int x = 0 - lims->x_min ;
	int y = 0 - lims->y_min ;
	int loc = 0;

	loc = (y *  lims->w) + x;
	arr[loc] = 1;
	while (str[i])
	{
		if (str[i] == '>')
			x += 1;
		else if (str[i] == '<')
			x -= 1;
		else if (str[i] == '^')
			y += 1;
		else if (str[i] == 'v')
			y -= 1;
		loc = (y *  lims->w) + x;
		arr[loc] = 1;
		i += 2;
	}
}

void print_arr(int *arr,int size, t_lims *lims)
{
	int i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		if (!(i % lims->w))
			printf("\n");
		i ++;
	}
}

int count_ones(int *arr,int size)
{
	int i = 0;
	int count = 0;
	while (i < size)
	{
		if (arr[i] == 1)
			count ++;
		i ++;
	}
	return (count);
}

int calc_stuff(char *line)
{
	t_lims lims;
	int val = 0;
	int *arr = NULL;
	lims.x_max = 0; 
	lims.y_max = 0;
	lims.x_min = 0; 
	lims.y_min = 0;
	lims.w = 0; 
	lims.h = 0;

	get_lims(line, &lims, 0);
	get_lims(line, &lims, 1);

	lims.w = lims.x_max - lims.x_min + 1;
	lims.h = lims.y_max - lims.y_min + 1;

	arr = malloc(sizeof(int) * lims.h * lims.w);
	if (!arr)
		return (0);
	mark_cords(line, &lims, arr, 0);
	mark_cords(line, &lims, arr, 1);
	val = count_ones(arr, lims.h * lims.w);
	//print_arr(arr, lims.h * lims.w, &lims);
	free (arr);
	return (val);
}

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	int i = 0;
	FILE	*fp;

	if (argc != 2)
		return (0);
	fp = fopen(argv[1], "r");
	while ((linelen = getline(&line, &linecap, fp)) > 0)
	{
		//printf("%s\n", line);
		i = calc_stuff(line);
		free (line);
	}
	fclose(fp);
	printf("result: %d\n", i);
	return (0);
}