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

int isbracket(char c)
{
    if (c == '(')
        return (1);
    if (c == ')')
        return (1);
    return (0);
}

char *func(char *str, int open)
{
    if (*str == '\0' && open == 0)
        return (NULL);
    else if (*str == '\0' && open != 0)
        return (str);
    else if (!isdigit(*str) && !is_sign(*str) && !isbracket(*str))
        return (str);
    else if (isdigit(*str) && *(str + 1) != '\0' )
    {
        if (isdigit(*(str + 1)))
            return (str + 1);
        else if (*(str + 1) == '(')
            return (str + 1);
        else
            return (func(str + 1, open));
    }
    else if (is_sign(*str) && *(str + 1) == '\0')
        return (str + 1);
    else if (is_sign(*str) && *(str + 1) != '\0')
    {
        if (isdigit(*(str + 1)) || *(str + 1) == '(')
            return (func(str + 1, open));
        else
            return (str + 1);
    }
    else if (*str == ')' && open <= 0)
        return (str);
    else if (*str == ')' && open > 0)
    {
        open--;
        if (*(str + 1) != '\0' && (is_sign(*(str + 1)) || (*(str + 1) == ')') ))
            return (func(str + 1, open));
        else if (*(str + 1) == '\0')
            return (func(str + 1, open));
        else
            return (str + 1);
    }
    else if (*str == '(')
    {
        open++;
        if (*(str + 1) != '\0' && (isdigit(*(str + 1)) || (*(str + 1) == '(') ))
            return (func(str + 1, open));
        else
            return (str + 1);
    }
    else
        return (func(str + 1, open));
}

int has_brackets(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(' || s[i] == ')')
            return (1);
        i++;
    }
    return (0);
}

int find_loc(char *s, char c)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
            return (i);
    }
    return (-1);
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
    else if (!has_brackets(s))
    {
        int loc = find_loc(s, '+');
        if (loc == -1)
        {
            loc = find_loc(s, '*');
            if (loc == -1)
            {
                *tree = new_node((node){.type=VAL, .val= *s -48, .l=NULL, .r=NULL});
                return;
            }
            else
            {
                s[loc] = '\0';
                *tree = new_node((node){.type=MULTI, .l=NULL, .r=NULL });
                make_tree(&(*tree)->l, s);
                make_tree(&(*tree)->r, s + loc + 1);
                return;
            }
        }
        else
        {
            s[loc] = '\0';
            *tree = new_node((node){.type=ADD, .l=NULL, .r=NULL });
            make_tree(&(*tree)->l, s);
            make_tree(&(*tree)->r, s + loc + 1);
            return;
        }
    }
    else if (has_brackets(s))
    {
        int loc = find_outside_loc(s);
        if (loc == -1)
        {
            if (*s == '(')
            {
                *s = '\0';
                s++;
            }
            if (s[ft_strlen(s) -1] == ')')
                s[ft_strlen(s) -1] = '\0';
            make_tree(tree, s);
        }
        else if(s[loc] == '+')
        {
            s[loc] = '\0';
            *tree = new_node((node){.type=ADD, .l=NULL, .r=NULL });
            make_tree(&(*tree)->l, s);
            make_tree(&(*tree)->r, s + loc + 1);
        }
        else if(s[loc] == '*')
        {
            s[loc] = '\0';
            *tree = new_node((node){.type=MULTI, .l=NULL, .r=NULL });
            make_tree(&(*tree)->l, s);
            make_tree(&(*tree)->r, s + loc + 1);
        }
    }
    return;
}

node *pars_expr(char *s)
{
    node *tree = NULL;
    if (!s)
        return (tree);
    char *ret = func(s, 0);
    if (!ret)
        make_tree(&tree, s);
    else
        unexpected(*ret);
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
