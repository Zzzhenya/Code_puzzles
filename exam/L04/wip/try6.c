#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int ft_err(char *str)
{
	if (!str)
		return (1);
	while (str)
	{
		write (2, str, 1);
		str++;
	}
	return (1);
}

int cd(char **argv, int end)
{
	if (end != 2)
		return (ft_err("error: cd: bad arguments\n"));
	if (chdir(argv[1]) == -1)
	{
		ft_err("error: cd: cannot change directory to ");
		ft_err(argv[1]);
		ft_err("\n");
		return (1);
	}
	return (0);
}

int ft_exec(char **argv, int i, char **envp)
{
	int status = 0;
	int fd[2];
	int has_pipe = (argv[i] && !strcmp(argv[i], "|"));

	if (!has_pipe && !strcmp(argv[0], "cd"))
		return (cd(argv, i));
	if (has_pipe && pipe(fd) == -1)
		return (ft_err("error: fatal\n"));
	int pid = fork();
	if (!pid)
	{
		argv[i] = 0;
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (ft_err("error: fatal\n"));
		if (!strcmp(argv[0], "cd"))
			return (cd(argv, i));
		execv(*argv, argv, envp);
		ft_err("error: cannot execute ");
		ft_err(argv[0]);
		ft_err("\n");
		return (1);
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (ft_err("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int argc, char **argv, char **envp)
{
	int status = 0;
	int i = 0;

	if (argc == 1)
		return (status);
	while (argv[i] && argv[i+1])
	{
		i++;
		argv += i;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (i)
			status = ft_exec(argv, i, envp);
	}
	return (status);
}