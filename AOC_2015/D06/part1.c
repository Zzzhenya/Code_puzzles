#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_chars
{
    char *act;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
} t_chars;

int find_no_lines(char *name)
{
    int len = 0;
    FILE	*fp;
    char *line = NULL;
	size_t linecap = 0;
    ssize_t linelen;

    fp = fopen(name, "r");
    while ((linelen = getline(&line, &linecap, fp)) > 0)
        len ++;
    fclose(fp);
    return (len);
}

t_chars *store_char_array(char *name, t_chars *storage)
{
    char *line = NULL;
	size_t linecap = 0;
    char *first = NULL;
	ssize_t linelen;
    char **arr = NULL;
    int i = 0;
    FILE	*fp;

    fp = fopen(name, "r");
    arr = malloc(sizeof(char *) * 3);
    while ((linelen = getline(&line, &linecap, fp)) > 0)
	{
        first = strtok(line, " ");
        if (strcmp(first, "toggle") == 0)
        {
            //storage[i].act = malloc(sizeof(char) * strlen(first) + 1);
            //strncpy(storage[i].act, first, strlen(first));
            //storage[i].act = first;
        }
        else
        {
            arr[0] = strtok(NULL, " ");
            //storage[i].act = malloc(sizeof(char) * strlen(arr[0]) + 1);
            //strncpy(storage[i].act, arr[0], strlen(arr[0]));
            //storage[i].act = arr[0];
        }
        arr[1] = strtok(NULL, " ");
        storage[i].start_x = atoi(strtok(arr[1], ","));
        storage[i].start_y = atoi(strtok(NULL, ","));
        strtok(NULL, " ");
        arr[2] = strtok(NULL, " ");
        storage[i].end_x = atoi(strtok(arr[2], ","));
        storage[i].end_y = atoi(strtok(NULL, ","));
        printf("%d \n", storage[i].start_x);
        i ++;
	}
    free (arr);
	fclose(fp);
    return(storage);
}

int main(int argc, char **argv)
{
    int len = 0;
    t_chars *storage = NULL;
	
	if (argc != 2)
		return (0);
    len  = find_no_lines(argv[1]);
    storage = malloc (sizeof(t_chars) * len + 1);
    storage = store_char_array(argv[1], storage);
	return (0);
}