#include <stdio.h>
#include <stdlib.h>

void print_arr(char **arr)
{
    int i = 0;

    while (arr[i])
    {
        printf("%s ", arr[i]);
        i++;
    }
    printf("\n");
}

int word_count(char *str, char delim)
{
    
}

char **ft_split(char *str, char delim)
{
    if (!str)
        return (NULL);
    char **arr = malloc(sizeof(char *) * (word_count(str, delim) + 1));
}

int main (int argc, char **argv)
{
    if (argc != 2)
        return (1);
    char **arr = ft_split(argv[1], ',');
    if (arr)
        print_arr(arr);
    //printf("Hello World\n");
    return (0);
}