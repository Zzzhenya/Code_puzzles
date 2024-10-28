#include <unistd.h>
#include <stdio.h>

int check_read(char c)
{
	if (c == 'r')
		return (1);
	else
		return (0);
}

//int writing_exec(char *cmd, char **cmdarr, char c)
void writing_exec(char *cmd, char **cmdarr, char c)
{
	//int ret;
	int fd[2];
	if (pipe(fd) == -1)
	{
		printf("Error\n");
		return;// (-1);
	}
	int pid = fork();
	if (!pid)
	{
		if (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
		{
			printf("Error\n");
			return;// (1);
		}
		execvp(cmd, cmdarr);
		printf("Execvp error\n");
		return;// (0);
	}
	else
	{
		if (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
		{
			printf("Error\n");
			return;// (1);
	  	}
		return;// (ret);
	}
}

// int reading_exec(char *cmd, char **cmdarr, char c)
void reading_exec(char *cmd, char **cmdarr, char c)
{
	//int ret;
	int fd[2];
	if (pipe(fd) == -1)
	{
		printf("Error\n");
		return;// (-1);
	}
	int pid = fork();
	if (!pid)
	{
		if (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
		{
			printf("Error\n");
			return;// (1);
		}
		execvp(cmd, cmdarr);
		printf("Execvp error\n");
		return;// (0);
	}
	else
	{
		if (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
		{
			printf("Error\n");
			return;// (1);
	  	}
		//return (ret);
	}
}

int implementation(char *cmd, char **cmdarr, char c)
{
	int is_read = check_read(c);
	// int fd[2];

	if (!is_read)
	{
		writing_exec(cmd, cmdarr, c);
		return (1);
	}
	else if (is_read)
	{
		reading_exec(cmd, cmdarr, c);
		return (0);
	}
	else
		return (-1);
	// if (pipe(fd) == -1)
	// {
	// 	printf("Error\n");
	// 	return (1);
	// }
	// int pid = fork();
	// if (!pid)
	// {
	// 	if (!is_read)
	// 	{
	// 		if (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
	// 		{
	// 			printf("Error\n");
	// 			return (1);
	// 		}
	// 	}
	// 	else if (is_read)
	// 	{
	// 		if (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
	// 		{
	// 			printf("Error\n");
	// 			return (1);
	// 		}
	// 	}
	// 	execvp(cmd, cmdarr);
	// 	printf("Execvp error\n");
	// 	return (1);
	// }
	// else
	// {
	// 	if (!is_read)
	// 	{
	// 		if (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
	// 		{
	// 			printf("Error\n");
	// 			return (1);
	//   		}
	// 	}
	// 	else if (is_read)
	// 	{
	// 		if (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
	// 		{	
	// 			printf("Error\n");
	// 			return (1);
	// 		}
	// 	}
	// }
}

int main(int argc, char **argv)
{
	if (argc != 4 )
	{
		write(1, "incorrect args\n", 15);
		return (1);
	}
	char c = argv[3][0];
	argv[3] = 0;
	int fd = implementation(argv[1], &argv[1], c);
	if (fd == 1 || fd == 0)
		close (fd);
	printf("fd: %d\n", fd);
	return (0);
}
