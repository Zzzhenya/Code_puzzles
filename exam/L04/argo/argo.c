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

int argo(json *dst, FILE *stream)
{
	(void)dst;
	int a = 1;
	if (!stream)
		return (-1);
	int c = peek(stream);
	if (c == '"')
	{
		printf("str: ");
		a = getc(stream);
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
			printf("%c", a);
		}
		printf("\n");
		//a = getc(stream);
		if (!expect(stream, c))
		 	return (-1);
		//argo(NULL, stream);
		return (1);
	}
	else if (isdigit(c))
	{
		int n = 0;
		a = c;
		printf("num: ");
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
		printf("%d\n", n);
		//argo(NULL, stream);
		return (1);
	}
	else if (c == '{')
	{
		char sep = ',';
		char next = ':';
		a = getc(stream);
		while (peek(stream) != EOF)
		{
			argo(NULL, stream);
			if (!expect(stream, next))
		 		return (-1);
			argo(NULL, stream);
			if (peek(stream) != sep)
				break;
			else
				getc(stream);
		}
		next = '}';
		if (!expect(stream, next))
		 	return (-1);
		return (1);
	}
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
