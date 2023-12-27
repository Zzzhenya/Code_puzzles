/*
#include <string.h>
#include <stdio.h>


Reproduce the behavior of the function strncmp (man strncmp)

The strcmp() and strncmp() functions 
lexicographically compare the null-
terminated strings s1 and s2

The strncmp() function compares not more than n characters.  
Because strncmp() is designed for comparing strings 
rather than binary data,
characters that appear after a ‘\0’ character are 
not compared.

The strcmp() and strncmp() functions return 
an integer greater than, equal to, or less than 0, 
according as the string s1 is greater than, equal to,
or less than the string s2.  
The comparison is done using 
unsigned characters, so that ‘\200’ is greater than ‘\0’
*/

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (i < n && s1[i] && s2[i])
	{
		ret = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (ret != 0)
			return (ret);
		i ++;
	}
	if (i < n && (s1[i] || s2[i]))
		ret = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (ret);
}
/*
int main (void)
{
	char *s1,*s2;

	s1 = "Abcaswwwwww";
	s2 = "Abcaswwwwww1";
	printf("%d\n", ft_strncmp(s1, s2, 1));
	printf("%d\n", strncmp(s1, s2, 1));
	return (0);
}*/