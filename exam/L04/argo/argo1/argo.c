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

int parse_int(json *dst, FILE *stream)
{
	dst->type = INTEGER;
	fscanf(stream, "%d", &dst->integer);
	return (1);
}

int ft_strlen(char *str)
{
	int len  = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

int parse_string(json *dst, FILE *stream)
{
	getc(stream);
	dst->type = STRING;
	dst->string = NULL;
	while (peek(stream) != EOF)
	{
		char a = getc(stream);
		if (a == '\\' && peek(stream) == '"')
			a = getc(stream);
		else if (a == '"')
		{
			ungetc(a, stream);
			break;
		}
		int len = ft_strlen(dst->string);
		dst->string = realloc(dst->string, len + 2);
		dst->string[len] = a;
		dst->string[len + 1] = '\0';
	}
	if (expect(stream, '"'))
		return (1);
	else
		return (-1);
}

char *get_string(FILE *stream)
{
	char *string = NULL;
	while (peek(stream) != EOF)
	{
		char a = getc(stream);
		if (a == '\\' && peek(stream) == '"')
			a = getc(stream);
		else if (a == '"')
		{
			ungetc(a, stream);
			break;
		}
		int len = ft_strlen(string);
		string = realloc(string, len + 2);
		string[len] = a;
		string[len + 1] = '\0';
	}
	if (expect(stream, '"'))
		return (string);
	else
		return (NULL);
}

int ft_argo(json *dst, FILE *stream)
{
	if (peek(stream) == '"')
		return (parse_string(dst, stream));
	else if (isdigit(peek(stream)) || peek(stream) == '+' || peek(stream) == '-' )
		return (parse_int(dst, stream));
	else if (peek(stream) == '{')
	{
		getc(stream);
		dst->type = MAP;
		dst->map.size = 1;
		dst->map.data = NULL;
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
			// detect start of key
			if (!expect(stream, '"'))
			 	return (-1);
			// extract key
			dst->map.data[dst->map.size - 1].key = get_string(stream);
			if (!dst->map.data[dst->map.size - 1].key)
				return (-1);
			// detect start of value
			if (!expect(stream, ':'))
		 		return (-1);
		 	// extract value
			ft_argo(&dst->map.data[dst->map.size - 1].value, stream);
			// check for more key value pairs
			if (peek(stream) != ',')
				break;
			else
			{
				dst->map.size++;
				getc(stream);
			}
		}
		// detect end of json object
		if (!expect(stream, '}'))
			return (-1);
	}
	return (1);
}

int argo(json *dst, FILE *stream)
{
	int ret = 0;
	if (!dst || !stream)
		return (-1);
	if (peek(stream)== '"')
		ret = parse_string(dst, stream);
	else if (isdigit(peek(stream)) || peek(stream) == '+' || peek(stream) == '-' )
		ret = parse_int(dst, stream);
	else if (peek(stream)== '{')
		ret = ft_argo(dst, stream);
	else
	{
		unexpected(stream);
        return (-1);
	}
	if (ret == 1)
	{
		if (accept(stream, EOF)) // for echo -n 'input'
			return (1);
		else if (accept(stream, '\n')) // for echo 'input'
			return (1);
		else
		{
			unexpected(stream);
			return (-1);
		}
	}
	else
		return (-1);
}
