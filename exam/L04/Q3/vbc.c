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

int ft_strlen(char *str)
{
    int len = 0;
    if (!str)
        return (len);
    while (str[len]!='\0')
        len++;
    return (len);
}

int is_sign(char c)
{
    if (c == '+')
        return (1);
    if (c == '*')
        return (1);
    return (0);
}

int find_outside_loc(char *s)
{
    int outside = 0;
    char c = '+';
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
            outside++;
        else if (s[i] == ')')
            outside--;
        else if (outside == 0 && s[i] == c)
            return (i);
    }
    c = '*';
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
            outside++;
        else if (s[i] == ')')
            outside--;
        else if (outside == 0 && s[i] == c)
            return (i);
    }
    return (-1);
}

void    make_tree(node **tree, char *s)
{
    if (ft_strlen(s) == 1 && isdigit(*s))
    {
        *tree = new_node((node){.type=VAL, .val= *s -48, .l=NULL, .r=NULL});
        return;
    }
    int loc = find_outside_loc(s);
    if (loc != -1)
    {
        if (s[loc] == '+')
        {
            s[loc] = '\0';
            *tree = new_node((node){.type=ADD, .l=NULL, .r=NULL });
            make_tree(&(*tree)->l, s);
            make_tree(&(*tree)->r, s + loc + 1);
        }
        else
        {
            s[loc] = '\0';
            *tree = new_node((node){.type=MULTI, .l=NULL, .r=NULL });
            make_tree(&(*tree)->l, s);
            make_tree(&(*tree)->r, s + loc + 1);
        }
    }
    else
    {
        if (*s == '(')
            s++;
        if (s[ft_strlen(s) - 1] == ')')
            s[ft_strlen(s) - 1] = '\0';
        make_tree(tree, s);
    }
}

char *parse_string(char *s, int open)
{
    if (*s == '\0' && open == 0)
        return (NULL);
    else if (*s == '\0' && open != 0)
        return (s);
    else if (*s != '\0' && isdigit(*s) && *(s + 1) != '\0' && isdigit(*(s+1)))
        return (s + 1);
    else if (*s != '\0' && isdigit(*s) && *(s + 1) != '\0' && *(s + 1) == '(')
        return (s + 1);
    else if (*s != '\0' && *s == '(' && *(s + 1) != '\0' && *(s + 1) == ')')
        return (s + 1);
    else if (*s != '\0' && *s == '(' && *(s + 1) != '\0' && is_sign(*(s + 1)))
        return (s + 1);
    else if (*s != '\0' && *s == ')' && open <= 0)
        return (s);
    else if (*s != '\0' && *s == ')' && *(s + 1) != '\0' && *(s + 1) == '(')
        return (s + 1);
    else if (*s != '\0' && *s == ')' && *(s + 1) != '\0' && isdigit(*(s + 1)))
        return (s + 1);
    else if (*s != '\0' && is_sign(*s) && *(s + 1) != '\0' && is_sign(*(s + 1)))
        return (s + 1);
    else if (*s != '\0' && is_sign(*s) && *(s + 1) != '\0' && *(s + 1) == ')')
        return (s + 1);
    else if (*s != '\0' && is_sign(*s) && *(s + 1) == '\0')
        return (s + 1);
    if (*s != '\0' && *s == '(')
        open++;
    if (*s != '\0' && *s == ')')
        open--;
    return (parse_string(s + 1, open));
}

node *pars_expr(char *s)
{
    node *tree = NULL;
    if (!s)
        return (tree);
    char *ret = parse_string(s, 0);
    if (!ret)
        make_tree(&tree, s);
    if (ret)
        unexpected(*ret);
    return (tree);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    node *tree = pars_expr(av[1]);
    if (!tree)
        return 1;
    printf("%d\n", eval_tree(tree));
    return (0);
}
