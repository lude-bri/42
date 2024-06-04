/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);

DESCRIPTION

 The strcspn() function spans the initial part of the null-terminated
string s as long as the characters from s do not occur in the null-
terminated string charset (it spans the complement of the charset). In
other words, it computes the string array index of the first character
of s which is also in charset, else the index of the first null character.

*/

#include <stdio.h>

size_t  ft_strcspn(const char *s, const char *reject)
{
    size_t i;
    size_t j;

    i = 0;
    //Looping pela string
    while(s[i++])
    {
        j = 0;
        // Check the current string char against every char in charset
        while (reject[j])
        {
            // Se encontrar, retorna o index;
            if (s[i] == reject[j++])
                return (i);
        }
    }
    // If we spanned the whole string, return i, in that case the
    // rejected char found is the NULL-terminating one
    return (i);
}