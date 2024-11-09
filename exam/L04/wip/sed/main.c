#include <stdio.h>
int main(void)
{
    char *line = NULL;
    size_t size = 100;
    int ret = getline(&line, &size, stdin);
    printf("%d: %s\n", ret, line);
    return (0);
}