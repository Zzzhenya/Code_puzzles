#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int ft_strlen(char *str)
{
	int len = 0;

	if (!str)
		return (len);
	while (str[len])
		len ++;
	return (len);
}

int ft_error(char *str)
{
	int len = 0;

	len  = ft_strlen(str);
	write (2, str, len);
	return (1);
}

int last_char_is_a_pipe(char **argv, int i)
{
	if ( argv[i] && !strcmp(argv[i], "|"))
		return (1);
	else
		return (0);
}

int exec_cd(char **argv, int i)
{
	if (i != 2)
	{
		ft_error("error: cd: bad arguments\n");
		return (1);
	}
	if (chdir(argv[1]) == -1)
	{
		ft_error("error: cd: cannot change directory to");
		ft_error(argv[1]);
		ft_error("\n");
		return (1);
	}
	return (0);
}

int setup_pipe_write(int fd[2])
{
	// duplicate stdout to pipeout
	if (dup2(fd[1], 1) == -1)
		return (-1);
	// close pipein
	if (close(fd[0]) == -1)
		return (-1);
	// close pipeout
	if (close(fd[1]) == -1)
		return (-1);
	return (0);
}

int setup_pipe_read(int fd[2])
{
	// duplicate stdin to pipein
	if (dup2(fd[0], 0) == -1)
		return (-1);
	// close pipein
	if (close(fd[0]) == -1)
		return (-1);
	//close pipeout
	if (close(fd[1]) == -1)
		return (-1);
	return (0);
}

int execute(char **argv, int i, char **env)
{
	int status = 0;
	int fd[2];

	// handle cd
	if (!last_char_is_a_pipe(argv, i) && !strcmp(*argv, "cd"))
	{
		status = exec_cd(argv, i);
		return (status);
	}
	// make pipe handle pipe errors
	if (last_char_is_a_pipe(argv, i) && pipe(fd) == -1)
	{
		ft_error("error: fatal\n");
		return (1);
	}
	// make child
	int pid = fork();
	if (pid == 0)
	{
		// NULL terminate argv
		argv[i] = 0;
		if (last_char_is_a_pipe(argv, i) && setup_pipe_write(fd) == -1)
		{
			ft_error("error: fatal\n");
			return (1);
		}
		/* If the command is 'cd', execute it
        if (!strcmp(*argv, "cd"))
            return cd(argv, i);*/
		// execute the command
		execve(*argv, argv, env);
		// execve fails
		ft_error("error: cannot execute ");
		ft_error(*argv);
		ft_error("\n");
		return (1);
	}
	//if (pid != 0)
	{
		// wait for child
		waitpid(pid, &status, 0);
    	// If the command includes a pipe and setting up the pipe fails, return an error
    	if (last_char_is_a_pipe(argv, i) && setup_pipe_read(fd) == -1)
    	{
    		ft_error("error: fatal\n");
        	return (1);
    	}
    	// Return the exit status of the child process
    	return WIFEXITED(status) && WEXITSTATUS(status);
	}
	return (status);
}


int main(int argc, char **argv, char **env)
{
	int status = 0;
	int i = 0;

	if (argc <= 1)
		return (status);
	while (argv[i] && argv[i + 1])
	{
		i++;
		argv += i;
		i = 0;
		while(argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (i) // this makes ; ; ; -> not go to the exec/printer loop
		{
			status = execute(argv, i, env);
		}
	}
	return (status);
}