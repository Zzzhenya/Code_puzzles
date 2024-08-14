#include <string.h>

int ft_exec(char **argv, int i, char **envp)
{
    (void)argv;
    (void)envp;
    return (i);
}

int    main(int argc, char **argv, char **envp)
{
    int status = 0;
    int i = 0;

    if (argc <= 1)
        return (status);
    while (argv[i] && argv[i+1])
    {
        i ++;
        argv += i;
        i = 0;
        while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
            i++;
        if (i)
            status = ft_exec(argv, i, envp);
    }
    return (status);
}