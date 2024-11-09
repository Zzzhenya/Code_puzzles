#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_cord
{
	float 		x;
	float 		y;
	int 		check;
	float 		dist;
}				t_cord;

size_t ft_strlen(char *str)
{
	size_t len = 0;
	
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

static int	arr_length(char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			len ++;
		}
		else if (*s == c)
			i = 0;
		s ++;
	}
	return (len);
}

static char	*ft_copy_str(char *s, int start, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (len - start + 1));
	if (!str)
		return (NULL);
	while (start < len)
	{
		str[i] = s[start];
		i ++;
		start ++;
	}
	str[i] = '\0';
	return (str);
}

static void	*ft_free(char **arr, int loc)
{
	int	i;

	i = 0;
	while (arr[i] && i <= loc)
	{
		free(arr[i]);
		arr[i] = NULL;
		i ++;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}

static char	**ft_whatever(char *s, char c, char **arr)
{
	int		start;
	size_t	i;
	int		str;

	i = 0;
	str = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			arr[str] = ft_copy_str(s, start, i);
			if (!arr[str])
				return (ft_free(arr, str));
			str ++;
			start = -1;
		}
		i++;
	}
	arr[str] = NULL;
	return (arr);
}

char	**ft_split(char *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (arr_length(s, c) + 1));
	if (!arr)
		return (NULL);
	arr = ft_whatever(s, c, arr);
	return (arr);
}


float convert_float(char **arr)
{
	float num = 0;
	float dec = 0;
	size_t i = 0;
	int c = 0;

	if (arr[0])
	{
		while (arr[0][i] != '\0' && arr[0][i] == ' ')
			i++;
		if (arr[0][i] != '\0' && arr[0][i] == '+')
			i++;
		else if (arr[0][i] != '\0' && arr[0][i] == '-')
		{
			num *= -1;
			i++;
		}
		while (arr[0][i] != '\0' && arr[0][i] >= '0' && arr[0][i] <= '9')
		{
			c = arr[0][i] - 48;
			num = (num * 10) + c;
			i++;
		}
	}
	i = 0;
	if (arr[1])
	{
		while (arr[1][i] != '\0' && arr[1][i] >= '0' && arr[1][i] <= '9')
		{
			c = arr[1][i] - 48;
			dec = (dec * 10) + c;
			i++;
		}
		while (dec > 1)
			dec /= 10;
	}
	return (num + dec);
}

void free_arr(char **arr)
{
	if (!arr || !arr[0])
		return;
	int i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	process_line(char *line, t_cord *cord, int *i)
{
	char **arr1 = ft_split(line, '\n');
	if (arr1[1])
		free(arr1[1]);
	char **arr2 = ft_split(arr1[0], ',');
	// printf("x: %s,\ty: %s\n", arr2[0], arr2[1]);

	char **x = ft_split(arr2[0], '.');

	char **y = ft_split(arr2[1], '.');
	if (x && y)
	{
		cord[*i].x = convert_float(x);
		cord[*i].y = convert_float(y);
		(*i)++;
	}
	free_arr(arr1);
	free_arr(arr2);
	free_arr(x);
	free_arr(y);
	//printf("x: main %s dec %s,\ty: main %s dec %s\n", x[0], x[1], y[0], y[1]);
}

void set_to_zero(t_cord *cord)
{
	int i = 0;

	while (i < 11)
	{
		cord[i].x = 0;
		cord[i].y = 0;
		cord[i].check = 0;
		cord[i].dist = INFINITY;
		i++;
	}
}

void	set_check_to_zero(t_cord *cord, int size)
{
	int i = 0;

	while (i < size)
	{
		cord[i].check = 0;
		cord[i].dist = INFINITY;
		i++;
	}
}

float distance(float x0, float y0, float x1, float y1)
{
	float p[2] = {
		fabs(x1 - x0),
		fabs(y1 - y0)
	};
	return (sqrtf(p[1] * p[1] + p[0] * p[0]));
}

float get_total(t_cord *cord, int size, t_cord end)
{
	int i = 0;
	float total = 0;

	while (i < size)
	{
		total += cord[i].dist;
		i ++;
	}
	total += end.dist;
	return (total);
}

int unchecked(t_cord *cord, int size)
{
	int i = 0;

	while (i < size)
	{
		if (cord[i].dist == INFINITY)
			return (1);
		i ++;
	}
	return (0);
}

void print_vals(t_cord *cord, int size)
{
	int i = 0;

	while (i < size)
	{
		printf("(%f, %f) :\t %f \t(%d)\n", cord[i].x, cord[i].y, cord[i].dist, cord[i].check);
		i ++;
	}
}

int set_start_and_end(t_cord *cord, int start, t_cord *end)
{
	int k = 0;

	end->x = cord[start].x;
	end->y = cord[start].y;
	end->check = 0;
	end->dist = INFINITY;

	cord[start].dist = 0;
	cord[start].check = k;
	k++;

	return (k);
}

float calc_path(t_cord *cord, int start, int size)
{
	t_cord end;

	int k = set_start_and_end(cord, start, &end);

	while (unchecked(cord, size))
	{
		int min_loc = 0;
		int i = 0;
		float dist = INFINITY;
		float min = INFINITY;
		while (i < size)
		{
			if (cord[i].dist == INFINITY)
			{
				dist = distance(cord[start].x, cord[start].y, cord[i].x, cord[i].y);
				if (dist < min)
				{
					min = dist;
					min_loc = i;
				}
			}
			i++;
		}
		cord[min_loc].check = k;
		k++;
		cord[min_loc].dist = min;
		start = min_loc;
	}
	end.dist = distance(cord[start].x, cord[start].y, end.x, end.y);
	end.check = k;
	//print_vals(cord, size);
	return (get_total(cord, size, end));
}

float process_data(t_cord *cord, int size)
{
	int i = 0;
	float ret = INFINITY;
	float min = INFINITY;

	while (i < size)
	{
		ret = calc_path(cord, i, size);
		if (ret < min)
			min = ret;
		printf("ret: %f\n", ret);
		set_check_to_zero(cord, size);
		i++;
	}
	return (min);
}

int main(void)
{
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	int i = 0;
	t_cord cord[11];

	set_to_zero(cord);
	while((linelen = getline(&line, &linecap, stdin)) > 0)
		process_line(line, cord, &i);
	free (line);
	float ret = process_data(cord, i);
	printf("answer: %0.2f\n", ret);
	return (0);
}