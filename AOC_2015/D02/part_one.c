#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ssize_t calc_area(char	*height, char *width, char *len)
{
	ssize_t h, w, l;
	ssize_t p1, p2, p3;
	ssize_t area = 0;

	h = atoi(height);
	w = atoi(width);
	l = atoi(len);
	p1 = 2 * l * w;
	p2 = 2 * w * h;
	p3 = 2 * h * l;
	area = p1 + p2 + p3;
	if (p1 <= p2 && p1 <= p3)
		area += (p1 / 2);
	else if (p2 <= p1 && p2 <= p3)
		area += (p2 / 2);
	else
		area += p3/2;
	return (area);
}

ssize_t ribbon_len(char	*height, char *width, char *len)
{
	ssize_t h, w, l;
	ssize_t size = 0;

	h = atoi(height);
	w = atoi(width);
	l = atoi(len);
	if (l >= w && l >= h)
		size = 2 * (h + w) ;
	else if (w >= l && w >= h)
		size = 2 * (h + l);
	else
		size = 2 * (w + l);
	size += (h * w * l);
	return (size);
}

int main(int argc, char **argv)
{
	char *line = NULL;
	char **arr = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	ssize_t area = 0;
	ssize_t len = 0;
	int i = 0;
	FILE	*fp;

	if (argc != 2)
		return (0);
	fp = fopen(argv[1], "r");
	arr = malloc(sizeof(char *) * 3);
	while ((linelen = getline(&line, &linecap, fp)) > 0)
	{
		arr[0] = strtok(line, "x");
		arr[1] = strtok(NULL, "x");
		arr[2] = strtok(NULL, "x");
		area += calc_area(arr[0], arr[1], arr[2]);
		len += ribbon_len(arr[0], arr[1], arr[2]);
	}
	free (arr);
	fclose(fp);
	printf("area: %zd\n", area);
	printf("len: %zd\n", len);
	return (0);
}