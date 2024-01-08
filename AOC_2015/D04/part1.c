#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "md5.h"
#include <math.h>

static int  count_digits(int n)
{
    int         count;
    long int    nb;

    count = 0;
    nb = n;
    if (nb <= 0)
    {
        count ++;
        nb = nb * -1;
    }
    while (nb)
    {
        nb = nb / 10;
        count ++;
    }
    return (count);
}

char    *ft_itoa(int n)
{
    char        *ptr;
    int         digits;
    long int    nbr;

    digits = count_digits(n);
    nbr = n;
    ptr = malloc(sizeof(char) * digits + 1);
    if (!ptr)
        return (NULL);
    ptr[digits] = '\0';
    if (nbr < 0)
        nbr = nbr * -1;
    while (digits > 0)
    {
        digits --;
        ptr[digits] = nbr % 10 + '0';
        nbr = nbr / 10;
    }
    if (n < 0)
        ptr[digits] = '-';
    return (ptr);
}

void print_hash(uint8_t *p){
    for(unsigned int i = 0; i < 16; ++i){
        printf("%02x", p[i]);
    }
    printf("\n");
}

char *convert_hexa(unsigned x, char *dest, size_t size) {
  snprintf(dest, size, "%X", x);
  return dest;
}

int has_45zero(uint8_t *val)
{
    int i = 0;
    char *str = malloc(sizeof(char)*100);
    int check = 0;

    memset(str, '\0', 100);
    while (i < 16)
    {
        str[i] = *convert_hexa(val[i], &str[i], 16);
        if (i == 0 && str[i] == '0')
            check ++;
        if (i == 1 && str[i] == '0')
            check ++;
        i ++;
    }
    if (check == 2)
        return (1);
    else
        return (0);
}

int has_6zero(uint8_t *val)
{
    int i = 0;
    char *str = malloc(sizeof(char)*100);
    int check = 0;

    memset(str, '\0', 100);
    while (i < 16)
    {
        str[i] = *convert_hexa(val[i], &str[i], 16);
        if (i == 0 && str[i] == '0')
            check ++;
        if (i == 1 && str[i] == '0')
            check ++;
        if (i == 2 && str[i] == '0')
            check ++;
        i ++;
    }
    if (check == 3)
        return (1);
    else
        return (0);
}

int combo(int digits, int *arr)
{
    int n = 0;
    int i = 0;

    while (n < pow(10, digits))
    {
        arr[i] = n;
        n ++;
        i ++;
    }
    return (i);
}

int main(void)
{
    //uint8_t result[16];
    uint8_t result[16];
    //char *str = "abcdef609043";
    char *str = "yzbqklnj";
    //char *str = "abcdef";
    char *num = NULL;
    int *arr = NULL;
    //uint8_t **arr = NULL; 
    int i = 0;
    int size = 0;
    int j = 1;
    int found = 0;

    arr = malloc(sizeof(int) * 1000000000);
    
    int len = 0;
    md5String(str, result);
    len = strlen(str);
    char *new = NULL;
    while (j < 8)
    {
        size = combo(j, arr);
        while (i < size)
        {
            new = malloc(sizeof(char) *  len + 100);
            memset(new, '\0', 100);
            strcpy(new, str);
            num = ft_itoa(arr[i]);
            strlcat(new, num, len + 100);
            //printf("%s : %s\n",new, num);
            md5String(new, result);
            if (has_45zero((uint8_t *)result))
            {
                printf("str: %s\n", new);
                print_hash(result);
                found ++;
            }
            if (has_6zero((uint8_t *)result))
            {
                printf("str: %s\n", new);
                print_hash(result);
                found ++;
            }
            free (new);
            if (found == 5)
                break;
            i ++;
        }
        j ++;
    }
    free(arr);
    return (0);
}