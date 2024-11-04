#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include "libft.h"

int ft_popen(const char *file, char *const argv[], char type)
{
	int fd[2];
	int pid;

	if (!file || !argv || !argv[0])
		return (-1);
	if (type != 'r' && type != 'w')
		return (-1);
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1); 
	if (pid == 0)
	{
		if (type == 'r')
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
		}
		else
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
		}
		if (execvp(file, argv) == -1)
			//return (-1);
			exit (-1);
	}
	if (type == 'r')
	{
		close(fd[1]);
		return (fd[0]);
	}
	else
	{
		close(fd[0]);
		return (fd[1]);
	}
}

int ft_strlen(char *str)
{
	int len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_read(char const *file, char *const av[])
{
	int fd = ft_popen(file, av, 'r');
	char *line = NULL;

	size_t linecap = 0;
	ssize_t linelen;
	if (fd >= 0)
	{
		printf("Success: %d\n", fd);
		FILE *stream = fdopen(fd, "r");
		while ((linelen = getline(&line, &linecap, stream)) > 0)
		{
			//fwrite(line, ft_strlen(line), 1, stdout);
			//fread(line, ft_strlen(line), 1, stdin);
			printf("%s", line);
			free(line);
			line = NULL;
		}
		close(fd);
	}
	else
		printf("Error: %d\n", fd);
}

void	ft_write(char const *file, char *const av[])
{
	int fd = ft_popen(file, av, 'w');
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	if (fd >= 0)
	{
		printf("Success: %d\n", fd);
		FILE *stream = fdopen(fd, "w");
		while ((linelen = getline(&line, &linecap, stream)) > 0)
		{
			//fwrite(line, ft_strlen(line), 1, stream);
			//fread(line, ft_strlen(line), 1, stdin);
			//fscanf(stdin, "%s", line);
			printf("%s", line);
			free(line);
			line = NULL;
		}
		// while (fscanf(stdin, "%s", line) != EOF)
		// 	fprintf(stream, "%s", line);
		close(fd);
	}
	else
		printf("Error: %d\n", fd);
}

int main(void)
{
	ft_read("ls", (char *const[]){"ls", NULL});
	// ft_read("abc", (char *const[]){"abc", NULL});
	ft_write("grep", (char *const[]){"grep", NULL});
	return (0);
}
