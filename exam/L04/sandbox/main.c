#include <stdbool.h>
#include <unistd.h>
#include<sys/wait.h>

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

int sandbox(void(*f)(void), unsigned int timeout, bool verbose)
{
    
}


int main(void)
{
    return (0);
}
