#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to write an error message to stderr
int err(char *str)
{
    // Loop through each character in the string and write it to stderr
    while (*str)
        write(2, str++, 1);
    return 1;
}

// Function to change the current working directory
int cd(char **argv, int i)
{
    // If the number of arguments is not 2, return an error
    if (i != 2)
        return err("error: cd: bad arguments\n");
    // If changing the directory fails, return an error
    if (chdir(argv[1]) == -1)
        return err("error: cd: cannot change directory to "), err(argv[1]), err("\n");
    return 0;
}

// Function to execute a command
int exec(char **argv, int i, char **envp)
{
    int fd[2];
    int status;
    // Check if the command includes a pipe
    int has_pipe = argv[i] && !strcmp(argv[i], "|");

    // If the command is 'cd', execute it
    if (!has_pipe && !strcmp(*argv, "cd"))
        return cd(argv, i);

    // If the command includes a pipe and creating the pipe fails, return an error
    if (has_pipe && pipe(fd) == -1)
        return err("error: fatal\n");

    // Fork the process
    int pid = fork();
    if (!pid)
    {
        argv[i] = 0;
        // If the command includes a pipe and setting up the pipe fails, return an error
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return err("error: fatal\n");
        // If the command is 'cd', execute it
        if (!strcmp(*argv, "cd"))
            return cd(argv, i);
        // Execute the command
        execve(*argv, argv, envp);
        // If executing the command fails, return an error
        return err("error: cannot execute "), err(*argv), err("\n");
    }

    // Wait for the child process to finish
    waitpid(pid, &status, 0);
    // If the command includes a pipe and setting up the pipe fails, return an error
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return err("error: fatal\n");
    // Return the exit status of the child process
    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp)
{
    int    i = 0;
    int    status = 0;

    if (argc > 1)
    {
        // Loop through each argument
        while (argv[i] && argv[++i])
        {
            // Move the pointer to the next argument
            argv += i;
            i = 0;
            // Loop through each argument until a pipe or semicolon is found
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++;
            // If there are arguments, execute them
            if (i)
                status = exec(argv, i, envp);
        }
    }
    return status;
}

// int main(int argc, char **argv, char **envp)
// {
//     int    i = 0;
//     int    status = 0;

//     // Continue if there are commands
//     if (argc > 1)
//     {
//         // while current and next command is not null
//         while (argv[i] && argv[++i])
//         {
//             // point argv to the next command line (after the ;)
//             argv += i;
//             // reset i
//             i = 0;
//             // While (command exists and is not a pipe) and not a semicolon; increment i
//             while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
//                 i++;
//             // if i is not 0 ( i.e there are commands); execute the current commandline, pick status from return
//             if (i)
//                 status = exec(argv, i, envp);
//         }
//     }
//     return status;
// }