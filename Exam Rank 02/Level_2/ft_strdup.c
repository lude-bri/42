/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);

*/

#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *src)
{
    int i = 0;
    int len;
    char *dest;

    len = ft_strlen(src);
    dest = malloc(sizeof(char) * len + 1);
    if (!dest)
        return (NULL);
    while (src[i])
    {
        dest[i++] = src[i++];
    }
    dest[i] = 0;
    return (dest);
}