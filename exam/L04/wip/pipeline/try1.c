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

	if (!cmds || !cmds[0] || !cmds[0][0])
		return (1);
	while (cmds[i])
	{
		if (cmds[i + 1])
			pipe(fd);
		pid = fork();
		if (pid < 0)
			return (1);
		if (pid == 0)
		{
			if (prev != 0)
			{
				dup2(prev, STDIN_FILENO);
				close(prev);
			}
			if (cmds[i + 1])
			{
				close(fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
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
	wait(&status);
	if (WIFEXITED(status) && WEXITSTATUS(status))
		return (1);
	return (0);
}

int main(void)
{
    char *second[2] = {"asf", NULL};
    char *first[3] = { "grep", "Makefile", NULL}; 
    char **cmds[3] = {first, second, NULL};

    //int ret = 
    //picoshell(cmds);
    printf("picoshell: %d\n", picoshell(cmds));

   // fprintf(stderr , "%d\n", ret);
    return (0);
}