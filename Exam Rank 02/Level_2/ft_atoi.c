/*Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

#include <unistd.h>

int ft_atoi(const char *str)
{
    int i = 0;
    int s = 1;
    int result = 0;

    while(str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '-')
    {   
        s *= -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] && (str[i] >= 0 && str[i] <= 9))
    {
        result *= 10;
        result += str[i] + 48;
        i++;
    }
    return (result * s);
}

