//#include <stdio.h>
#include <stdlib.h>

/*
void	print_arr(char **arr)
{
	int i = 0;

	if (!arr)
		return;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i ++;
	}
	printf("%s\n", arr[i]);
}
*/
int  word_count (char *str)
{
	int i = 0;
	int count = 0;
	int check = 1;

	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			check = 1;
		}
		else
		{
			if (check == 1)
			{
				count ++;
				check = 0;
			}
		}
		i++;
	}
	return (count);
}

char	*ft_copy_string(char *dest, char *src, int len)
 {
 	int i = 0;

 	while (i < len)
 	{
 		dest[i] = src[i];
 		i ++;
 	}
 	dest[i] = '\0';
 	return(dest);
 }


char  **ft_split(char *str)
{
	int arr_len = 0;
	char **arr;
	int i = 0;
	int k = 0;
	int start = 0;

	arr_len = word_count(str);
	arr = (char **)malloc(sizeof(char *) * arr_len + 1);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > start)
		{
			arr[k] = (char *)malloc(sizeof(char) * ((i - start) + 1));
			ft_copy_string(arr[k], &str[start], i - start);
			k ++;
		}
	}
	arr[k] = NULL;
	return (arr);
}

/*
int main(void)
{
	char **arr;

	arr = ft_split("Hello World");
	print_arr(arr);
	return (0);
}*/