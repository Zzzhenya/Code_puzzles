#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define STDIN 0
#define STDOUT 1

void print_cmds(char **cmds[])
{
	for (int i = 0; cmds[i]; i++)
	{
		for (int j = 0; cmds[i][j]; j++)
			printf("%s ", cmds[i][j]);
		printf("\n");
	}
}

int count_cmds(char **cmds[])
{
	int i = 0;
	if (!cmds || !cmds[i])
		return (i);
	while (cmds[i])
		i++;
	return (i);
}

int exec_cmd(char *cmd[], int last, int first)
{
	//int status;
	(void)first; (void)last;
	//static int state = -1;
	int fd[2];
	if (pipe(fd) == -1)
		return (1);
	int pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT);
		close(fd[1]);
		execvp(cmd[0], cmd);
		return (1);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN);
		close(fd[0]);
		return (0);
	}
}

int picoshell(char **cmds[])
{
	//print_cmds(cmds);
	int status;
	int cmd_count = count_cmds(cmds);
	int i = 0;
	while (i < cmd_count)
	{
		if (i == 0 && i + 1 != cmd_count)
			status = exec_cmd(cmds[i], 0, 1);
		else if (i == 0 && i + 1 == cmd_count)
			status = exec_cmd(cmds[i], 1, 1);
		else if (i + 1 == cmd_count)
			status = exec_cmd(cmds[i], 1, 0);
		else
			status = exec_cmd(cmds[i], 0, 0);
		i++;
	}
	// wait(&status);
	wait(NULL);
	if (WIFEXITED(status))
		WEXITSTATUS(status);
	if (status)
		return (1);
	else
		return (0);
}

int main(void)
{
	//char *first[2] = {"/bin/ls", NULL};
	char *first[3] = {"asjkfasf", "-la",  NULL};
	//char *second[3] = {"grep", "picoshell", NULL};
	char *second[2] = {"ls", NULL};

	//char **cmds[3] = {first, second, NULL};
	char **cmds[3] = {first, second, NULL};
	printf("status: %d\n", picoshell(cmds));

	return (0);
}