#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int sandbox(void(*f)(void), unsigned int timeout, bool verbose);

/* test the function pointerd by f is good or bad;

good - return 1; bad - return 0; if sandbox error - return -1
bad - 
    if terminated or stop by signal (sigsev etc.)
    if exists with any code other than 0
    if it timesout
    etc.

if verbose == true
    write explicit message
else
    write exit code
*/

void function1(void)
{
    while (1)
    {
        write(1, "ABC\n", 4);
        sleep(1);
    }
}

void function3(void)
{
    sleep(4);
    exit(1);
}

#include <string.h>
void function2(void)
{
    char *str = NULL;
    strlen(str);
}

int sandbox(void(*f)(void), unsigned int timeout, bool verbose)
{
    (void)verbose;
    int status = 0;
    if (timeout > 100000000 || !f  || timeout == 0)
        return (-1);
    int pid = fork();
    if (pid < 0)
        return (-1);
    if (pid == 0)
    {
        //if (
        if (alarm(timeout) != 0)
            return (-1);
        //    return (-1);
        f();
        return (0);
    }
    else
    {
        waitpid(pid, &status, 0);
        if (WIFSIGNALED(status))
        {
            int val = WTERMSIG(status);
            printf("Exited with sig %s\n", strsignal(val));
            return (0);
        }
        else if (WIFEXITED(status))
        {
            int val = WEXITSTATUS(status);
            printf("Exited with exitcode %d\n", val);
            return (0); 
        }
        else
            return (1);
    }
}

int main(void)
{
    printf("sandbox: %d %d\n", 1,  sandbox(function1, 3, false));
    printf("sandbox: %d %d\n", 2,  sandbox(function2, 1000, false));
    printf("sandbox: %d %d\n", 1,  sandbox(function1, 0, false));
    printf("sandbox: %d %d\n", 1,  sandbox(function3, 5, false));
    printf("sandbox: %d %d\n", 1,  sandbox(function4, 10, false));
    //function2();
    return (0);
}
