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

int find_plus(char *str)
{
    int i = 0;
    if (!str)
        return (-1);
    while (str[i] != '\0')
    {
        if (str[i] == '+')
            return (i);
        i++;
    }
    return (-1);
}

int find_mult(char *str)
{
    int i = 0;
    if (!str)
        return (-1);
    while (str[i] != '\0')
    {
        if (str[i] == '*')
            return (i);
        i++;
    }
    return (-1);
}

node *make_tree(node *tree, char *s)
{
    int loc = 0;
    if (find_plus(s) == -1 || !find_mult(s))
    {
        tree = new_node((node){.type=VAL, .val=atoi(s), .l=NULL, .r=NULL});
    }
    if (find_plus(s) != -1)
    {
        loc = find_plus(s);
        if (loc != -1)
        {
            s[loc]= '\0';
            tree = new_node((node){.type=ADD, .l=NULL, .r=NULL });
            tree->l = (make_tree(tree->l, s));
            tree->r = (make_tree(tree->r, s + loc + 1));
        }
    }
    if (find_mult(s) != -1)
    {
        loc = find_mult(s);
        if (loc != -1)
        {
            s[loc]= '\0';
            tree = new_node((node){.type=MULTI, .l=NULL, .r=NULL});
            tree->l = (make_tree(tree->l, s));
            tree->r = (make_tree(tree->r, s + loc + 1));
        }
    }
    return (tree);
}

void    print_tree(node *tree)
{
    if (!tree)
    {
        printf("Empty");
        return;
    }
    switch (tree->type)
    {
        case(VAL):
            printf("%d\n", tree->val);
            break;
        case(ADD):
            print_tree(tree->l);
            print_tree(tree->r);
            break;
        case(MULTI):
            print_tree(tree->l);
            print_tree(tree->r);
            break;

    }
}

int is_number(char *s, int i)
{
    if (s[i] == '\0')
    {
        unexpected(s[i]);
        return (-1);     
    }
    else if (s[i] != '\0')
    {
        if (s[i] == '+' || s[i] == '-')
            i++;
    }
    if (!(s[i] != '\0' && isdigit(s[i])))
    {
        unexpected(s[i]);
        return (-1);       
    }
    while (s[i] != '\0' && isdigit(s[i]))
        i++;
    return (i);
}

node *pars_expr(char *s)
{
    node *tree = NULL;

    if (!s)
        return (tree);
    int i = 0;
    int ret = 0;
    if (s[i] != '\0')
    {
        ret = is_number(s, i);
        if (ret == -1)
            return (tree);
        i = ret;
    }
    while (s[i] != '\0')
    {
        if (s[i] != '\0' && (s[i] == '+' || s[i] == '*'))
            i++;
        else
        {
            unexpected(s[i]);
            return(tree);
        }
        ret = is_number(s, i);
        if (ret == -1)
            return (tree);
        i = ret;
    }
    tree = make_tree(tree, s);
    //print_tree(tree);
    return (tree);
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