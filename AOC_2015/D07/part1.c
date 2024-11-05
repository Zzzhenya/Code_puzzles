#include <stdio.h>

int ft_strlen(char *str)
{
    int len =0;
    if (!str)
        return (len);
    while (str[len] != '\0')
        len++;
    return(len);
}

int main(int argc, char **argv)
{
    if (argc !=2 )
        return (1);
    char *str = argv[1];

    char 
    int chr_str = ft_strlen(str);
    printf("%d\n", chr_str);
    //strip_first and last quotes
    
    //int ret = total_string_literal_count -  total_chars_in_memory 
    return (0);
}