#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

typedef struct node {

    enum {
        ADD,
        MULTI,
        VAL
    } type;

    int             val;
    struct node     *l;
    struct node     *r;
} node;

node *parse_expr(char **s);

node *new_node(node n)
{
    node *ret = calloc(1, sizeof(node));
    if (!ret)
        return NULL;
    *ret = n;
    return ret;
}

void unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input");
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return 1;
    }
    return 0;
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return 1;
    unexpected(**s);
    return 0;
}
int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return tree->val;
    }
    return(1);
}

node *parse_nbr(char **s)
{
    if (isdigit(**s))
    {
        node n = {.type = VAL, .val=**s - '0', .r=NULL, .l=NULL};
        (*s)++;
        return (new_node(n));
    }
    unexpected(**s);
    return (NULL);
}

node *parse_fact(char **s)
{
    if (accept(s, '('))
    {
        node *expr = parse_expr(s);
        if (!expect(s, ')'))
            return (NULL);
        return (expr);
    }
    return (parse_nbr(s));
}

node *parse_term(char **s)
{
    node *left = parse_fact(s);
    while (accept(s, '*'))
    {
        node *right = parse_fact(s);
        if (!right)
        {
            //destroy_tree(left);
            return (NULL);
        }
        node n = {.type=MULTI, .l = left, .r=right};
        left = new_node(n);
    }
    return (left);
}

node *parse_expr(char **s)
{
    node *left = parse_term(s);
    while (accept(s, '+'))
    {
        node *right = parse_term(s);
        if (!right)
        {
            //destroy_tree(left);
            return (NULL);
        }
        node n = {.type=ADD, .l = left, .r=right};
        left = new_node(n);
    }
    return (left);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    node *tree = parse_expr(&(av[1]));
    if (!tree)
        return 1;
    printf("%d\n", eval_tree(tree));
    return (0);
}