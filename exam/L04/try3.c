#include <unistd.h>
#include <stdlib.h>
#include <string.h>

size_t ft_strlen(char *str)
{
    size_t len = 0;

    if (!str)
        return (len);
    while (str[len] != '\0')
        len++;
    return (len);
}

int  print_pipeline(char **argv, int i)
{
    write(1, argv[0], ft_strlen(argv[0]));
    write (1, "\n" , 1);
    if (i > 1)
    {
        write(1, argv[i-1], ft_strlen(argv[i-1]));
        write (1, "\n" , 1);
    }
    return (5);
}

int main (int argc, char **argv, char **envp)
{
    int status = 0;
    int i = 0;

    if (argc <= 2)
    {
        (void)argv;
        (void)envp;
        return (status);
    }
    while (argv[i] && argv[i+1])
    {
        i++;
        argv += i;
        i = 0;
        while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
            i++;
        if (i)
        {
            status = print_pipeline(argv, i);
        }
    }
    return (status);
}