#include "argo.h"

/*
int getc (FILE *stream)
obtains the next input character if present from the stream
pointed at by stream, or the next character pushed back on
the stream via ungetc
*/

int peek(FILE *stream)
{
	int c = getc(stream);
	ungetc(c, stream);
	return (c);
}

void unexpected(FILE *stream)
{
	if (peek(stream) != EOF)
		printf("Unexpected token '%c'\n", peek(stream));
	else
		printf("Unexpected end of input\n");
}

int accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream);
		return(1);
	}
	return (0);
}

int expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return (1);
	unexpected(stream);
	return (0);
}

int ft_strlen(char *str)
{
	int len = 0;
	if (!str)
		return(len);
	while (str[len])
		len++;
	return (len);
}

char	*add_letter(char *str, char c)
{
	// if (!str)
	// {
	// 	str = malloc(sizeof(char) * 2);
	// 	str[0] = c;
	// 	str[1] = '\0';
	// 	return (str);
	// }
	int len = ft_strlen(str);
	char *cpy = malloc(sizeof(char) * len + 2);
	for (int i = 0; i < len; i++)
		cpy[i] = str[i];
	cpy[len] = c;
	cpy[len+1] = '\0';
	if (str)
		free(str);
	return(cpy);

}

int argo(json *dst, FILE *stream)
{
	char c = peek(stream);
	if (c  == '"')
	{
		dst->type = STRING;
		char *str = NULL;
		int i = 0;
		int check = 0;
		while (1)
		{
			c = getc(stream);
			if (c == '"')
			{
				if (str && str[i - 1] && str[i - 1] == '\\')
				{
					str[i - 1] = c;
				}
				else if (check == 1)
					break;
				else
					check = 1;
			}
			else
			{
				str = add_letter(str, c);
				i++;
			}
		}
		dst->string = str;
		return (1);
	}
	else if (isdigit(c))
	{
		dst->type = INTEGER;
		int n = 0;
		int val = 0;
		val = getc(stream);
		while (isdigit(val))
		{
			n = n * 10 + (val - 48);
			val = getc(stream);
		}
		dst->integer = n;
		return(1);
	}
	else
	{
		dst->type = MAP;
		dst->map.data = malloc(sizeof(pair) * 1);
		dst->map.size = 1;
		c = getc(stream);
		// extract key
		char *k = NULL;
		int i = 0;
		int check = 0;
		while (1)
		{
			c = getc(stream);
			if (c == '"')
			{
				if (k && k[i - 1] && k[i - 1] == '\\')
				{
					k[i - 1] = c;
				}
				else if (check == 1)
					break;
				else
					check = 1;
			}
			else
			{
				k = add_letter(k, c);
				i++;
			}
		}
		dst->map.data->key = k;
		//if (peek(stream) == ',')
			// add another map data
			// increase the size by 1
		if (peek(stream) == ':')
		{
			getc(stream);
			return ( argo(&dst->map.data->value, stream));
		}
	}

		// if (accept(stream, '{'))
		// 	printf("A\n");
	return(1);
}
/*
	char *str = malloc(sizeof(char) * 10);
	for (int i = 0; i < 10; i++)
		str[i] = '\0';
	int i = 0;
	char c;
	int check = 0;
	while (1)
	{
		c = getc(stream);
		// printf("%c\n", c);
		if (c == '"')
		{
			if (str[i - 1] && str[i - 1] == '\\')
			{
				str[i - 1] = c;
			}
			else if (check == 1)
				break;
			else
				check = 1;
		}
		else
		{
			str[i] = c;
			i++;
		}
	}
	printf("str: %s\n", str);
	dst->type = STRING;
	dst->string = str;
*/
