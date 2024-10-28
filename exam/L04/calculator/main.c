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

int accept(char *s, char c)
{
    if (*s == c)
    {
        (*s)++;
        return 1;
    }
    return 0;
}

int expect(char *s, char c)
{
    if (accept(s, c))
        return 1;
    unexpected(*s);
    return 0;
}

node *pars_expr(char *s)
{
    (void)s;
    node *tree = malloc(sizeof(node))
    // int n = 0;
    // static node *tree = NULL;
    // if (*s == '\0')
    //     return (tree);
    // if (isdigit(*s))
    // {
        
    //     while (isdigit(*s))
    //     {
    //         printf("%c", *s);
    //         s++;
    //     }
    //     tree = new_node((node){.type=VAL, .val=4});
    //     tree->r = NULL;
    //     tree->l = NULL;
    //     //if (*s == '\0')
    //     return(pars_expr(s)); 
    // }
    // if (*s == '+')
    // {
    //     printf("%c", *s);
    //     s++;
    //     return(pars_expr(s));
    // }
    // if (*s == '*')
    // {
    //     printf("%c", *s);
    //     s++;
    //     return(pars_expr(s));
    // }
    return (tree);

// change here
    // if (*s)
    // {
    //     free(ret);
    //     return NULL;
    // }
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
}
int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    node *tree = pars_expr(av[1]);
    if (!tree)
        return 1;
    printf("%d\n", eval_tree(tree));
}