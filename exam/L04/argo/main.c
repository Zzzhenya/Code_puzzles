
/*
argo.c
getc, ungetc, printf, malloc, calloc, realloc, free, isdigit, fscanf, write

write following function so that it will parse a json file in the structure declared in argo.h
s
int argo(json *dst, FILE *stream);

dst - pointer to the AST that you will create
stream - file to parse 

return 1 for success and -1 for failure
for unexpected token, print to stdout - "Unexpected token '%c'\n" or "Unexpected end of input\n" if token is EOF
*/

#include "argo.h"

void free_json(json j)
{
	switch (j.type)
	{
		case MAP:
			for (size_t i = 0; i < j.map.size; i++)
			{
				free(j.map.data[i].key);
				free_json(j.map.data[i].value);
			}
			free(j.map.data);
			break;
		case STRING:
			free(j.string);
			break;
		default:
			break;
	}
}

void	serialize(json j)
{
	switch(j.type)
	{
		case INTEGER:
			printf("%d", j.integer);
			break;
		case STRING:
			putchar('"');
			for (int i = 0; j.string[i]; i++)
			{
				if (j.string[i] =='\\' || j.string[i] == '"')
					putchar('\\');
				putchar(j.string[i]);
			}
			putchar('"');
			break;
		case MAP:
			putchar('{');
			for(size_t i = 0; i < j.map.size; i++)
			{
				if (i != 0)
					putchar(',');
				serialize((json){.type=STRING, .string = j.map.data[i].key});
				putchar(':');
				serialize(j.map.data[i].value);
			}
			putchar('}');
			break;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r");
	json file;
	if (argo(&file, stream) != 1)
	{
		free_json(file);
		return(1);
	}
	serialize(file);
	printf("\n");
}