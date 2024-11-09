#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *arr[2] = {"/bin/ls", "-la"};

void child(int *fd)
{
	dup2(fd[1],1);
	close(fd[0]);
	close(fd[1]);
	execvp(arr[0], arr);
	return;
}

int func()
{
	int fd[2];
	pipe(fd);
	int pid = fork();
	if (!pid)
	{
		child(fd);
		return (-1);
	}
	else
	{
		dup2(fd[0],0);
		close(fd[0]);
		close(fd[1]);
		return (0);
	}
}

int func1()
{
	int fd[2];
	pipe(fd);
	int pid = fork();
	if (!pid)
	{
		dup2(fd[0],0);
		close(fd[0]);
		close(fd[1]);
		execvp(arr[0], arr);
		return (-1);
	}
	else
	{
		dup2(fd[1],1);
		close(fd[0]);
		close(fd[1]);
		return (1);
	}
}

int main(void)
{
	int ret = func();
	char str[5];
	// memset(str, '\0', 500);
	// read(ret, str, 499);
	// printf("%s\n", str);

	ret = func1();
	return (0);
}