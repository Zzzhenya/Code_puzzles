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

int argo(json *dst, FILE *stream)
{
	(void)dst;
	if (!expect(stream, '{'))
		return (-1);
	while (peek(stream) != EOF)
	{
		if (!expect(stream, '"'))
			return (-1);
		while (1)
		{
			int c = getc(stream);
			if (c == '"' || c == EOF)
			{
				ungetc(c, stream);
				break;
			}
			else
				printf("%c", c);
		}
		printf("\n");
		if (!expect(stream, '"'))
			return (-1);
		if (!expect(stream, ':'))
			return (-1);
		if (peek(stream) == '{')
			argo(dst, stream);
		else if (peek(stream) == ':')
			argo(dst, stream);
	}
	if (!expect(stream, '}'))
		return (-1);
	if (!expect(stream, EOF))
		return (-1);
	return (1);
}
