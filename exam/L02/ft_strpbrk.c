/*#include <string.h>
#include <unistd.h>

The strpbrk() function locates in the null-terminated string s 
the first occurrence of any character in the string charset and returns 
a pointer to this character.  
If no characters from charset occur anywhere in s strpbrk() returns NULL.

void ft_putchar(char c)
{
     write (1, &c, 1);
     write (1, "\n", 1);
}*/

char *ft_strpbrk(const char *s, const char *charset)
{
     int i = 0;
     int j;

     while (charset[i])
     {
          j = 0;
          while (s[j])
          {
               if (s[j] == charset[i])
                    return ((char *)&s[j]);
               j ++;
          }
          i ++;
     }
     return (0);
}
/*
int main(void)
{
     char *str;

     str = strpbrk("0 ", "   a");
     if (str)
          ft_putchar(*str);
     return (0);
}*/