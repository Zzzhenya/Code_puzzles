#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct json {
    enum { MAP, INTEGER, STRING} type;
    union {
        struct {
                struct pair *data;
                size_t size;
        } map;
        int integer;
        char *string;
    };
} json;

typedef struct pair {
    char *key;
    json value;
} pair;

int argo (json *dst, FILE *stream);

int peek(FILE *stream) {
    int c = getc(stream);
    ungetc(c, stream);
    return c;
}

void unexpected(FILE *stream) {
    if (peek(stream) != EOF)
        printf("unexpected token %c\n", peek(stream));
    else
        printf("unexpected end of input\n");
}

int accept(FILE *stream, char c) {
    if (peek(stream) == c) {
        (void) getc(stream);
        return 1;
    }
    return 0;
}

int expect(FILE *stream, char c) {
    if (accept(stream, c)) {
        return 1;
    }
    unexpected(stream);
    return 0;
}

void free_json(json *j) {
    if (j->type == STRING) {
        free(j->string);
    } else if (j->type == MAP) {
        for (size_t i = 0; i < j->map.size; i++) {
            free(j->map.data[i].key);
            free_json(&j->map.data[i].value);
        }
        free(j->map.data);
    }
}

char *get_string(FILE *stream) {
    char *buffer = malloc(256 * sizeof(char));
    int i = 0;
    while (peek(stream) != '"' && (peek(stream) != EOF || peek(stream) != '\n')) {
        buffer[i++] = getc(stream);
    }
    buffer[i] = '\0';
    if (!expect(stream, '"')) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

int parse_string(json *dst, FILE *stream) {
    dst->type = STRING;
    dst->string = get_string(stream);
    if (!dst->string) {
        return -1;
    }
    return 1;
}

int parse_integer(json *dst, FILE *stream) {
    dst->type = INTEGER;
    dst->integer = 0;
    while (isdigit(peek(stream))) {
        dst->integer = dst->integer * 10 + getc(stream) - '0';
    }
    return 1;
}

int parse_map(json *dst, FILE *stream) {
    dst->type = MAP;
    dst->map.data = malloc(256 * sizeof(pair));
    if (!dst->map.data) {
        return 1;
    }
    int i = 0;
    dst->map.size = 0;
    while (peek(stream) != '}' && (peek(stream) != EOF || peek(stream) != '\n')) {
        while (peek(stream) != '}' && (peek(stream) != EOF || peek(stream) != '\n')) {
            if (accept(stream, ',')) 
                break;
            if (!expect(stream, '"')) {
                free_json(dst);
                return -1;
            }
            dst->map.data[i].key = get_string(stream);
            if (!dst->map.data[i].key) {
                free_json(dst);
                return -1;
            }
            if (!expect(stream, ':')) {
                free_json(dst);
                return -1;
            }
            argo(&dst->map.data[i].value, stream);
        }
        i++;
        dst->map.size++;
    }
    if (!expect(stream, '}')) {
        free_json(dst);
        return -1;
    }
    return 1;
}

int argo (json *dst, FILE *stream) {
    if (accept(stream, '{')) 
        return parse_map(dst, stream);
    else if (accept(stream, '"'))
    {
        if (parse_string(dst, stream))
        {
            if (expect(stream, EOF) || expect(stream, '\n'))
                return (1);
            else
                return (-1);
        }
        else
            return (-1);
    }
    else if (isdigit(peek(stream)))
    {
        if (parse_integer(dst, stream))
        {
            if (expect(stream, EOF) || expect(stream, '\n'))
                return (1);
            else
                return (-1);
        }
        else
            return (-1);
    }
    else {
        unexpected(stream);
        return -1;
    }
}

void print_json(json *j) {
    switch (j->type) {
        case MAP:
            printf("{");
            for (size_t i = 0; i < j->map.size; i++) {
                if (i > 0) {
                    printf(",");
                }
                printf("\"%s\": ", j->map.data[i].key);
                print_json(&j->map.data[i].value);
            }
            printf("}");
            break;
        case STRING:
            printf("\"%s\"", j->string);
            break;
        case INTEGER:
            printf("%d", j->integer);
            break;
        default:
            printf("null");
            break;
    }
}

int main(int ac, char **av) {
    if (ac != 2) {
        printf("Usage: ./json_parser \"json\"\n");
        return 1;
    }
    FILE *stream = fopen(av[1], "r");
    if (!stream) {
        perror("fmemopen");
        return 1;
    }
    json j;
    if (argo(&j, stream) == -1) {
        fclose(stream);
        return 1;
    }
    print_json(&j);
    free_json(&j);
    return 0;
} 