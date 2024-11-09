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

char *make_string(FILE *stream, char c)
{
	char *str = NULL;
	int a = getc(stream);
	while (a != EOF)
	{
		a = getc(stream);
		if (( a == '\\' && peek(stream) == c) || (a != c))
		{
			if ( a == '\\' && peek(stream) == c)
				a = getc(stream);
		}
		else if (a == c)
		{
			ungetc(a, stream);
			break;
		}
		str = add_letter(str, a);
	}
	if (!expect(stream, c))
	{
		if (str)
			free(str);
		return (NULL);
	}
	return (str);
}

int make_integer(FILE *stream, int c)
{
	int n = 0;
	int a = c;
	while (a != EOF)
	{
		a = getc(stream);
		if (isdigit(a))
			n = (n * 10) + (a - 48);
		else
		{
			ungetc(a, stream);
			break;
		}
	}
	return (n);
}

int argo(json *dst, FILE *stream)
{
	int a = 1;
	if (!stream)
		return (-1);
	int c = peek(stream);
	if (c == '"')
	{
		dst->type = STRING;
		dst->string = make_string(stream, c);
		if (!dst->string)
			return (-1);
<<<<<<< Updated upstream
=======
		// printf("%s\n", dst->string);
		//return (1);
>>>>>>> Stashed changes
	}
	if (isdigit(c) || (c == '+' || c == '-'))
	{
		int sign = 1;
		if (c == '+' || c == '-')
		{
			a = getc(stream);//  int i; fscanf(stream, "%d", i);
			if (a == '-')
				sign *= -1;
		}
		if (!isdigit(peek(stream)))
		{
			unexpected(stream);
			return (-1);
		}
		dst->type = INTEGER;
		dst->string = NULL;
		dst->integer = make_integer(stream, c);
		dst->integer *= sign;
<<<<<<< Updated upstream
=======
		// printf("num: ");
		// printf("%d\n", dst->integer);
		//return (1);
>>>>>>> Stashed changes
	}
	if (c == '{')
	{
		dst->type = MAP;
		dst->map.size = 1;
		dst->map.data = NULL;
		char sep = ',';
		char next = ':';
		a = getc(stream);
		while (peek(stream) != EOF)
		{
			pair *temp = NULL;
			temp = realloc( dst->map.data , sizeof(pair) * dst->map.size);
			if (dst->map.data)
				free (dst->map.data);
			dst->map.data = temp;
			dst->map.data[dst->map.size - 1].value.type = MAP;
			dst->map.data[dst->map.size - 1].value.map.size = 0;
			dst->map.data[dst->map.size - 1].value.map.data = NULL;
			c = peek(stream);
			// if (!expect(stream, '"'))
		 	// 	return (-1);
			dst->map.data[dst->map.size - 1].key = make_string(stream, c);
			if (!dst->map.data[dst->map.size - 1].key)
				return (-1);
			if (!expect(stream, ':'))
		 		return (-1);
			return(argo(&dst->map.data[dst->map.size - 1].value, stream));
			if (peek(stream) != sep)
				break;
			else
			{
				dst->map.size++;
				getc(stream);
			}
		}
		next = '}';
		if (!expect(stream, next))
		 	return (-1);
<<<<<<< Updated upstream
	}
	if (!expect(stream, EOF))
		return (-1);
	else
		return(1);
=======
		}
		//return (1);
	}
	if (expect(stream, EOF))
		// dst->type = MAP;
		// dst->map.size = 0;
		// dst->map.data = NULL;
		return (-1);
	else
		return (1);
>>>>>>> Stashed changes
}
