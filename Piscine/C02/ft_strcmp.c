/* 
#include <string.h>
#include <stdio.h>

Reproduce the behavior of the function 
strcmp (man strcmp)

The strcmp() and strncmp() functions 
lexicographically compare the null-
terminated strings s1 and s2

The strcmp() and strncmp() functions return 
an integer greater than, equal to, or less than 0, 
according as the string s1 is greater than, equal to,
or less than the string s2.  
The comparison is done using 
unsigned characters, so that ‘\200’ is greater than ‘\0’
*/

int	ft_strcmp(char *s1, char *s2)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i ++;
	ret = (unsigned char)s1[i] - (unsigned char)s2[i];
	return(ret);
}
/*
int main (void)
{
	char *s1,*s2;

	s1 = "Abc";
	s2 = "Ac";
	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d\n", strcmp(s1, s2));
	return (0);
}*/