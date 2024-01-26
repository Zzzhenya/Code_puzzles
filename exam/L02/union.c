#include <unistd.h>

int ft_strlen(char *str)
{
	int len = 0;
	if (!str)
		return (len);
	while (str[len])
		len ++;
	return (len);
}

char *ft_copy(char *str, char *s1,char * s2)
{
	int i = 0;
	int k = 0;
	int j = 0;

	str[i] = s1[k];
	i ++;
	k ++;
	while (s1[k] != '\0')
	{
		j = 0;
		while (j < k)
		{
			if (s1[j] == s1[k])
				break;
			j ++;
		}
		if (j == k)
		{
			str[i] = s1[k];
			i ++;
		}
		k ++;
	}
	k = 0;	
	while (s2[k] != '\0')
	{
		j = 0;
		while (j < k + i)
		{
			if (str[j] == s2[k])
				break;
			j ++;
		}
		if (j == k + i)
		{
			str[i] = s2[k];
			i ++;
		}
		k ++;
	}
	str[i] = '\0';
	return (str);
}


void	ft_union(char *s1, char *s2, int len)
{
	int i = 0;
	int j = 0;
	char str[len + 1];

	ft_copy(str, s1, s2);
	write(1, &str, ft_strlen(str));
}

int main (int argc, char **argv)
{
	int len = 0;

	if (argc == 3)
	{
		len = ft_strlen(argv[1]) + ft_strlen(argv[2]) + 1;
		ft_union(argv[1], argv[2], len);
	}
	write (1, "\n", 1);
}