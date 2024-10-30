#include <stdio.h>
#include <math.h>

typedef struct s_cord
{
	double x;
	double y;
}				t_cord;

float distance(float x0, float y0, float x1, float y1)
{
	float p[2] = {
		fabs(x1 - x0),
		fabs(y1 - y0)
	};
	return (sqrtf(p[1] * p[1] + p[0] * p[0]));
}

void	print_arr(int len, int combi[len])
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", combi[i]);
	}
	printf("\n");
}

int no_repeats(int len, int combi[len], int val)
{
	for (int i = 0; i < len; i++)
	{
		if (combi[i] == val)
			return (0);
	}
	return (1);
}

double get_distance(int len, t_cord arr[len], int combi[len])
{
	double total = 0;
	t_cord path[len+1];
	for (int i = 0; i < len; i++)
	{
		path[i].x = arr[combi[i]].x;
		path[i].y = arr[combi[i]].y;
	}
	path[len].x = arr[combi[0]].x;
	path[len].y = arr[combi[0]].y;
	for (int i = 0; i < len; i++)
	{
		total += distance(path[i].x, path[i].y, path[i+1].x, path[i+1].y);
	}
	return (total);
}

void	find_combi(int len, t_cord arr[11], int combi[len], int idx)
{
	static double min = INFINITY;
	if (arr == NULL)
	{
		printf("min: %.2f\n", min);
		return;
	}
	if (idx == len)
	{
		//print_arr(len, combi);
		double temp = get_distance(len, arr, combi);
		printf("temp: %.2f\n", temp);
		if (temp < min)
			min = temp;
		return;
	}
	int i = 0;
	while (i < len)
	{
		if (no_repeats(idx, combi, i))
		{
			combi[idx] = i;
			find_combi(len, arr, combi, idx+1);
		}
		i++;
	}
}

int main(void)
{
	t_cord arr[11];
	int len = 0;
	while (fscanf(stdin, "%lf, %lf", &arr[len].x, &arr[len].y) != EOF)
		len++;
	// int i = 0;
	// while (i < len)
	// {
	// 	printf("%lf, %lf\n", arr[i].x, arr[i].y);
	// 	i++;
	// }
	int combi[len];
	find_combi(len, arr, combi, 0);
	find_combi(len, NULL, combi, 0);
	return (0);
}