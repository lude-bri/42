/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);

SYNOPSIS
     #include <string.h>
     char *strpbrk(const char *s, const char *charset);

DESCRIPTION
     The strpbrk() function locates in the null-terminated string s the first
     occurrence of any character in the string charset and returns a pointer to this
     character.  If no characters from charset occur anywhere in s strpbrk()
     returns NULL.
RETURN VALUES
     The strpbrk() function return a pointer to the first occurence of any character
     in the string,if no characters occur anywhere in s, strpbrk() returns NULL.
*/

#include <string.h>

char *strpbrk(const char *s, const char *charset)
{
    int i;
    int j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (charset[j])
        {
            if (s[i] == charset[j])
                return (s[i]);
            j++;
        }
        i++;
    }
    return (NULL);
}