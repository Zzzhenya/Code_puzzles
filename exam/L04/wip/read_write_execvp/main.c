#include <unistd.h>
#include <stdio.h>

int make_fork(char **arr, int mode)
{
	int fd[2];
	pipe(fd);
	int pid = fork();
	if (pid == 0)
	{
		if (mode == 'w')
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]); close(fd[1]);
		}
		else if (mode == 'r')
		{
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]); close(fd[1]);
		}
		execvp(arr[0], arr);
		//exit(1);
	}
	//close(fd[0]); close(fd[1]);
	if (mode == 'w')
	{
		close(fd[0]);
		return (fd[1]);
	}
	else
	{
		close(fd[1]);
		return (fd[0]);
	}
}

int main (int argc, char **argv)
{
	// char buffer[1000];
	// for (int i = 0; i < 1000; i++)
	// 	buffer[i] = '\0';
	if (argc != 4)
		return (1);
	int mode = argv[3][0];
	argv[3] = 0;
	char **arr = argv + 1;
	int ret = make_fork(arr, mode);
	if (mode == 'w')
		write (ret, "Hello\n", 6);
	else
		write (ret, "Hello\n", 6);
		//read(ret, buffer, 100);
	//printf("%d\n", mode);	
	// write (ret, buffer , 6);
	return (0);
}
