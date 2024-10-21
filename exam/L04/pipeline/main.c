#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define STDIN 0
#define STDOUT 1

typedef struct s_cmd
{
	int in;
	int out;
}				t_cmd;

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

int exec_cmd(char *cmd[], int pipe_count, t_cmd arr[pipe_count], int i)
{
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		if (arr[i].out != STDOUT)
		{
			if (dup2(arr[i].out, STDOUT) == -1)
				return (1);
			if (close(arr[i].out) == -1)
				return (1);
		}
		if (arr[i].in != STDIN)
		{
			if (dup2(arr[i].in, STDIN) == -1)
				return (1);
			if (close(arr[i].in) == 1)
				return (1);
		}
		if (execvp(cmd[0], cmd) == -1)
			return (1);
	}
	else
	{
		if (arr[i].out != STDOUT)
			close(arr[i].out);
		if (arr[i].in != STDIN)
			close(arr[i].in);
	}
	return (0);
}

int setup_pipes(int cmd_count, t_cmd arr[cmd_count])
{
	for (int i = 0; i < cmd_count; i++)
	{
		arr[i].in = STDIN;
		arr[i].out = STDOUT;
	}
	int pipe_count = cmd_count - 1;
	if (pipe_count)
	{
		for (int i = 0; i < pipe_count; i++)
		{
			int fd[2];
			if (pipe(fd) == -1)
				return (0);
			if (i == 0 || i + 1 == pipe_count)
			{
				if (i == 0)
					arr[i].out = fd[1];
				if (i + 1 == pipe_count)
					arr[i+1].in = fd[0];
			}
			else
			{
				arr[i].in = fd[0];
				arr[i].out = fd[1];
			}
		}
	}
	return (1);
}

int picoshell(char **cmds[])
{
	//print_cmds(cmds);
	int status = 0;
	int cmd_count = count_cmds(cmds);
	t_cmd arr[cmd_count];
	if (!setup_pipes(cmd_count, arr))
		return (1);
	int pipe_count = cmd_count - 1;
	int ret = 0;
	int check = 0;
	for (int i = 0; i < cmd_count; i++)
	{
		ret = exec_cmd(cmds[i], pipe_count, arr, i);
		if (ret && check == 0)
			check = 1;
	}
	wait(&status);
	if (status || check)
		return (1);
	else
		return (0);
}

int main(void)
{
	char *first[2] = {"ls",  NULL};
	//char *first[3] = {"asjkfasf", "-la",  NULL};
	char *second[3] = {"grep", "Makefile" , NULL};
	//char *second[2] = {"ls", NULL};

	char **cmds[3] = {first, second, NULL};
	//char **cmds[2] = {first, NULL};
	printf("picoshell status: %d\n", picoshell(cmds));

	return (0);
}