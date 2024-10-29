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

/*
2 + 4 x 5 + 1 = 23
    node *tree = malloc(sizeof(node));
    tree->type = ADD;
    tree->r = new_node((node){
        .type=ADD, 
        .l=new_node((node){
            .type=MULTI, 
            .l=new_node((node){
                .type=VAL, 
                .val= 4}),
            .r=new_node((node){
                .type=VAL, 
                .val= 5})}),
        .r=new_node((node){
            .type=VAL, 
            .val=1})});
    tree->l = new_node((node){.type=VAL, .val=2});
    return (tree);
*/
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
        tree = new_node((node){.type=VAL,.val=atoi(s), .l=NULL, .r=NULL});
    }
    if (find_plus(s) != -1)
    {
        loc = find_plus(s);
        if (loc != -1)
        {
            s[loc]= '\0';
            tree = new_node((node){
                .type=ADD,
                .l=NULL,
                .r=NULL
            });
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
            tree = new_node((node){
                .type=MULTI,
                .l=NULL,
                .r=NULL
            });
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

node *pars_expr(char *s)
{
    node *tree=NULL;

    tree = make_tree(tree, s);
    //print_tree(tree);
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