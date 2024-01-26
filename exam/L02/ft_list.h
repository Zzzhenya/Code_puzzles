#ifndef FT__LIST_H
# define FT__LIST_H

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

#endif