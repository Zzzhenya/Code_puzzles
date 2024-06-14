#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#define WIDTH 1000
#define HEIGHT 1000

void    exec_toggle(int *buf, char *line)
{
    (void)buf;
    //printf("line: %s\n", line);
    printf("toggle  \t");   
    printf("start : %s\t", strtok(NULL, " "));
    strtok(NULL, " ");
    printf("end : %s\n", strtok(NULL, " "));
}

void    exec_turn(int *buf, char *line)
{
    (void)buf;
    //printf("line: %s\n", line);
    printf("on/off : %s\t", strtok(NULL, " "));
    printf("start : %s\t", strtok(NULL, " "));
    strtok(NULL, " ");
    printf("end : %s\n", strtok(NULL, " "));
}

void    get_range_calc(int *buf, char *file)
{
    char *line = NULL;
	size_t linecap = 0;
    char *first = NULL;
	ssize_t linelen;
    // char **arr = NULL;
    int i = 0;
    FILE	*fp;

    fp = fopen(file, "r");
    if (!fp)
    {
        perror(file);
        return;
    }
    // arr = malloc(sizeof(char *) * 3);
    while ((linelen = getline(&line, &linecap, fp)) > 0)
	{
        //printf("%s", line);
        if (line[strlen(line) - 1] == '\n')
            first = strtok(line, "\n");
        first = strtok(line, " ");
        if (strcmp(first, "toggle") == 0)
        {
            exec_toggle(buf, line);
        //     //storage[i].act = malloc(sizeof(char) * strlen(first) + 1);
        //     //strn   cpy(storage[i].act, first, strlen(first));
        //     //storage[i].act = first;
        }
        else
        {
            exec_turn(buf, line);
        //     // arr[0] = strtok(NULL, " ");   
        //     //storage[i].act = malloc(sizeof(char) * strlen(arr[0]) + 1);
        //     //strncpy(storage[i].act, arr[0], strlen(arr[0]));
        //     //storage[i].act = arr[0];
        }
        // arr[1] = strtok(NULL, " ");
        // storage[i].start_x = atoi(strtok(arr[1], ","));
        // storage[i].start_y = atoi(strtok(NULL, ","));
        // strtok(NULL, " ");
        // arr[2] = strtok(NULL, " ");
        // storage[i].end_x = atoi(strtok(arr[2], ","));
        // storage[i].end_y = atoi(strtok(NULL, ","));
        // printf("%d \n", storage[i].start_x);
        i ++;
        first = NULL;
        free (line);
	}
    // free (arr);
	fclose(fp);
}

int main(int argc, char **argv)
{
    int *buf;

    if (argc != 2)
        return (0);
    buf = (int *)malloc(sizeof(int) * (WIDTH * HEIGHT));
    memset(buf, 0, 1000000);
    get_range_calc(buf, argv[1]);
    free(buf);
    return (0);
}