#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int sandbox(void(*f)(void), unsigned int timeout, bool verbose);

/* test the function pointerd by f is good or bad;

good - return 1; bad - return 0; if sandbox error - return -1
bad - 
    if terminated or stop by signal (sigsev etc.)
    if exists with any code other than 0
    if it timesout

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

int sandbox(void(*f)(void), unsigned int timeout, bool verbose)
{
    (void)verbose;
    int status = 0;
    if (timeout > 100000000 || !f)
        return (-1);
    int pid = fork();
    if (pid < 0)
        return (-1);
    if (pid == 0)
    {
        //if (
        alarm(timeout);// == 0)
        //    return (-1);
        f();
        return (0);
    }
    else
    {
        waitpid(pid, &status, 0);
        return (WIFSIGNALED(status) && WTERMSIG(status));
    }
}

#include <stdio.h>

int main(void)
{
    printf("sandbox: %d\n", sandbox(function1, 3, false));
    return (0);
}
