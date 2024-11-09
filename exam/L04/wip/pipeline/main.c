#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define STDIN 0
#define STDOUT 1

int g_status = 0;

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

int exec_cmd(char *cmd[], int cmd_count, t_cmd arr[cmd_count], int i)
{
	//int status = 0;
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		if (arr[i].out != STDOUT)
			dup2(arr[i].out, STDOUT);
		if (arr[i].in != STDIN)
			dup2(arr[i].in, STDIN);
		if (execvp(cmd[0], cmd) == -1)
		{
			if (arr[i].in != STDIN)
				close(arr[i].in);
			if (arr[i].out != STDOUT)
				close(arr[i].out);
			g_status = 1;

		}
		return (g_status);
	}
	else
	{
		if (arr[i].out != STDOUT)
			close(arr[i].out);
		if (arr[i].in != STDIN)
			close(arr[i].in);
		return (g_status);
		// wait(&status);
		// return ((WIFEXITED(status)) &&	WEXITSTATUS(status));
	}
}

int setup_pipes(int cmd_count, t_cmd arr[cmd_count], char **cmds[], int fd[2])
{
	for (int i = 0; i < cmd_count; i++)
	{
		arr[i].in = STDIN;
		arr[i].out = STDOUT;
	}
	for (int i = 0; i < cmd_count; i++)
	{
		if (cmds[i + 1])
		{
			if (pipe(fd) == -1)
				return (0);
			if (arr[i].out == STDOUT)
				arr[i].out = fd[1];
			if (arr[i + 1].in == STDIN)
				arr[i+1].in = fd[0];
			if (arr[i].out != fd[1])
				close(fd[1]);
			if (arr[i + 1].in != fd[0])
				close(fd[0]);
		}
	}
	return (1);
}

int picoshell(char **cmds[])
{
	//print_cmds(cmds);
	//int status = 0;
	int pid = fork();
	if (!pid)
	{
		int cmd_count = count_cmds(cmds);
		//printf("cmds: %d\n", cmd_count);
		t_cmd arr[cmd_count]; 
		int fd[2];
		setup_pipes(cmd_count, arr, cmds, fd);
		int ret = 0;
		int check = 0;
		for (int i = 0; i < cmd_count; i++)
		{
			ret = exec_cmd(cmds[i], cmd_count, arr, i);
			if (ret && !check)
				check = ret;
		}
		// wait(&g_status);
		// if (WIFEXITED(g_status))
		// 	WEXITSTATUS(g_status);
		if (g_status || ret || check)
			exit (1);
		else
			exit (0);
	}
	else
	{
		int new_stat = 0; 
		wait(&new_stat);
		return (WIFEXITED(new_stat) && WEXITSTATUS(new_stat));
	}
}

int main(void)
{
	char *first[2] = {"ahjasgfjhasf",  NULL};
	//char *first[2] = {"ls",  NULL};
	char *second[3] = {"grep", "Makefile" , NULL};
	//char *second[2] = {"asjhf", NULL};

	//char **cmds[4] = {first, second, third, NULL};
	char **cmds[3] = {first, second, NULL};
	int ret =  picoshell(cmds);
	fprintf(stderr, "picoshell :%d\n", ret);
	return (0);
}