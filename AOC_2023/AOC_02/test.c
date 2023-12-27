#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void    fill_str(char *res, char *s1, char *s2)
{
    unsigned int    i;
    unsigned int    j;

    i = 0;
    j = 0;
    while (s1[j])
        res[i++] = s1[j++];
    j = 0;
    while (s2[j])
        res[i++] = s2[j++];
    res[i] = '\0';
}

char    *ft_strjoin(char *s1, char *s2)
{
    char            *res;

    res = (char *) malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
    if (!res)
        return (NULL);
    fill_str(res, s1, s2);
    return (res);
}

char    *ft_substr(char *s, unsigned int start, size_t len)
{
    size_t    i;
    char    *str;

    if (!s)
        return (NULL);
    if (start > strlen(s))
        return (malloc(1));
    if (len > strlen(s + start))
        len = strlen(s + start);
    str = malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = 0;
    return (str);
}

static char *_set_line(char *line_buffer)
{
    char    *left_c; 
    ssize_t    i;
    
    i = 0;
    while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
        i++;
    if (line_buffer[i] == 0 || line_buffer[1] == 0)
        return (NULL);
    left_c = ft_substr(line_buffer, i + 1, strlen(line_buffer) - i);
    if (*left_c == 0)
    {
        free(left_c);
        left_c = NULL;
    }
    line_buffer[i+1] = 'F';
    //line_buffer[i + 1] = 0;
    return (left_c);
}

char    *_fill_line_buffer(char *left_c)
{
  char *buffer;
  buffer = (char *)malloc((15 + 1) * sizeof(char));
  buffer = "Hello\nghgdfghj";
  left_c = ft_strjoin(left_c, buffer);
  return (left_c);
}

int main() {
  static char *left_c = "World";
  char        *line;
  
  
  line = _fill_line_buffer(left_c);
  left_c = _set_line(line);
  printf("line: %s\n", line);
  printf("left_c: %s\n", left_c);
  return 0;
}