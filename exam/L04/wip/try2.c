#include <string.h>
#include <unistd.h>
#include <stdio.h>

/*

Your program must implement the built-in 
command cd only with a path as argument 
(no '-' or without parameters)

if cd has the wrong number of argument 
your program should print in STDERR 
"error: cd: bad arguments" followed by a '\n'

if cd failed your program should print 
in STDERR 
"error: cd: cannot change directory to path_to_change" 
followed by a '\n' with path_to_change replaced by the argument to cd
a cd command will never be immediately followed or preceded by a "|"
*/

int ft_strlen(char *str)
{
	int len = 0;

	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_error(char *msg, char *path)
{
	if (msg)
		write (2, msg, ft_strlen(msg));
	if (path)
		write (2, path, ft_strlen(path));
	write (2, "\n", 1);
	return (1);
}

int exec_cd(char **argv, int i)
{
	//if cd has the wrong number of argument 
	//your program should print in STDERR 
	//"error: cd: bad arguments" followed by a '\n'
	printf("%d\n", i);
	if (i != 2)
		ft_error("error: cd: bad argumens", NULL);
		//return (ft_error("error: cd: bad argumens", NULL));
	// if (chdir(argv[1]) == -1)
	// 	return (ft_error("error: cd: cannot change directory to ", argv[1]));
	// else
	ft_error("error: cd: cannot change directory to ", argv[0]);
	return (0);

}

int ft_execute(char **argv, int i, char **envp)
{
	(void)envp;
	int status = 0;
	int has_a_pipe = (argv[i] && strcmp(argv[i], "|"));

	if (!has_a_pipe && strcmp(*argv , "cd"))
	{
		status = exec_cd(argv, i);
		return (status);
	}
	else
		printf("not cd: %s\n", argv[0]);
	return (status);
}

int main(int argc, char **argv, char **envp)
{
	int status = 0;
	int i = 0;

	if (argc <= 1)
		return (status);
	i ++; // should I?
	while (argv[i] && argv[i + 1])
	{
		i ++;
		argv += i;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (i)
			status = ft_execute(argv, i, envp);
	}
	return (status);
}