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

int exec_cmd(char *cmd[], int cmd_count, int fds[cmd_count][2], int loc)
{
	(void)fds;
	static int prev_fd = -1;
	int fd[2];
	if (pipe(fd) == -1)
		return (1);
	int pid = fork();
	if (pid == 0)
	{
		if (prev_fd == -1)
		{
			dup2(fd[1], STDOUT);
			close(fd[1]);
			close(fd[0]);
		}
		if (loc == cmd_count - 1)
		{
			dup2(prev_fd, STDIN);
			close(prev_fd);
			close(fd[0]);
		}
		else
		{
			dup2(prev_fd, STDIN);
			close(prev_fd);
			dup2(fd[1], STDOUT);
			close(fd[1]);
			close(fd[0]);
		}
		execvp(cmd[0], cmd);
		return (1);
	}
	else
	{
		prev_fd = fd[0];
		if (prev_fd != -1)
			close(fd[0]);
		close(fd[1]);
		return (0);
	}
}

int picoshell(char **cmds[])
{
	//print_cmds(cmds);
	int status;
	int cmd_count = count_cmds(cmds);
	int i = 0;
	int fds[cmd_count][2];
	while (i < cmd_count)
	{
		//first, last middle
		if (i == 0 )
			status = exec_cmd(cmds[i],cmd_count, fds, i);
		else if (i == cmd_count - 1)
			status = exec_cmd(cmds[i],cmd_count, fds, i);
		else if (i > 0)
			status = exec_cmd(cmds[i],cmd_count, fds, i);
		i++;
	}
	wait(&status);
	// wait(NULL);
	if (WIFEXITED(status))
		WEXITSTATUS(status);
	if (status)
		return (1);
	else
		return (0);
}

int main(void)
{
	char *first[2] = {"ls",  NULL};
	//char *second[3] = {"asjkfasf", "-la",  NULL};
	char *second[3] = {"grep", "Makefile" , NULL};
	//char *first[2] = {"ls", NULL};

	char **cmds[3] = {first, second, NULL};
	//char **cmds[2] = {first, NULL};
	printf("picoshell status: %d\n", picoshell(cmds));

	return (0);
}