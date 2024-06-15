#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#define WIDTH 1000
#define HEIGHT 1000

void    switch_on_off(size_t **buf, char *start, char *end, int val)
{
    int x0 = 0;
    int y0 = 0;
    int x1 = 0;
    int y1 = 0;
    int ytemp = 0;
    x0 = (size_t)atoi(strtok(start, ","));
    y0 = (size_t)atoi(strtok(NULL, ","));
    x1 = (size_t)atoi(strtok(end, ","));
    y1 = (size_t)atoi(strtok(NULL, ","));
    ytemp = y0;
    while (x0 <= x1)
    {
        y0 = ytemp;
        while (y0 <= y1)
        {
            if (val < 0)
            {
                if ((*buf)[(x0 * WIDTH) + y0] > 0)
                    (*buf)[(x0 * WIDTH) + y0] += val;
            }
            else
                (*buf)[(x0 * WIDTH) + y0] += val;
            y0 += 1;
        }
        x0 += 1;
    }
}

void    exec_toggle(size_t **buf, char *line)
{
    char *start = NULL;
    char *end = NULL;

    start = strtok(NULL, " ");
    strtok(NULL, " ");
    end = strtok(NULL, " ");
    switch_on_off(buf, start, end, 2);
}

void    exec_turn(size_t **buf, char *line)
{
    char *start = NULL;
    char *end = NULL;
    if (strcmp("on", strtok(NULL, " ")) == 0)
    {
        start = strtok(NULL, " ");
        strtok(NULL, " ");
        end = strtok(NULL, " ");
        switch_on_off(buf, start, end, 1);
        return;
    }
    else
    {
        start = strtok(NULL, " ");
        strtok(NULL, " ");
        end = strtok(NULL, " ");
        switch_on_off(buf, start, end, -1);
        return;
    }
}

void    get_range_calc(size_t **buf, char *file)
{
    char *line = NULL;
	size_t linecap = 0;
    char *first = NULL;
	ssize_t linelen;
    int i = 0;
    FILE	*fp;

    fp = fopen(file, "r");
    if (!fp)
    {
        perror(file);
        return;
    }
    while ((linelen = getline(&line, &linecap, fp)) > 0)
	{
        if (line[strlen(line) - 1] == '\n')
            first = strtok(line, "\n");
        first = strtok(line, " ");
        if (strcmp(first, "toggle") == 0)
        {
            exec_toggle(buf, line);
        }
        else
        {
            exec_turn(buf, line);
        }
        i ++;
        first = NULL;
	}
    i = 0;
    int sum = 0;
    while (i < (WIDTH * HEIGHT))
    {
        sum += (*buf)[i];
        // printf("%zu", (*buf)[i]);
        // if ((i + 1)%WIDTH == 0)
        //     printf("\n");
        i ++;
    }
    printf("result: %d\n", sum);
	fclose(fp);
}

int main(int argc, char **argv)
{
    size_t *buf;

    if (argc != 2)
        return (0);
    buf = (size_t *)malloc(sizeof(size_t) * (WIDTH * HEIGHT));
    memset(buf, 0, 100);
    get_range_calc(&buf, argv[1]);
    free(buf);
    return (0);
}