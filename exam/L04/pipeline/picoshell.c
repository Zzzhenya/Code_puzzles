#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int picoshell(char **cmds[])
{
    int i = 0;
    int prev = 0;
    int status = 0;
    int fd[2];
    int pid;

    while (cmds[i])
    {
        if (cmds[i + 1])
        {
            if (pipe(fd) == -1)
                return (1);
        }
        pid = fork();
        if (pid < 0)
            return (1);
        if (pid == 0)
        {
            if (prev != 0)
            {
                if (dup2(prev, STDIN_FILENO) == -1)
                    return (1);
                if (close(prev) == -1)
                    return (1);
            }
            if (cmds[i+1])
            {
                if (close(fd[0]) == -1)
                    return (1);
                if (dup2(fd[1], STDOUT_FILENO) == -1)
                    return (1);
                if (close(fd[1]) == -1)
                    return (1);
            }
            if (execvp(cmds[i][0], cmds[i]) == -1)
                exit(1);
        }
        else
        {
            if (prev != 0)
                close(prev);
            if (cmds[i + 1])
            {
                close(fd[1]);
                prev = fd[0];
            }
        }
        i++;
    }
    while (wait(&status) < 0);
    return (0);
}

int main(void)
{
    char *first[2] = {"asf", NULL};
    char *second[3] = { "grep", "Makefile", NULL}; 
    char **cmds[3] = {first, second, NULL};

    //int ret = 
    //picoshell(cmds);
    printf("picoshell: %d\n", picoshell(cmds));

   // fprintf(stderr , "%d\n", ret);
    return (0);
}