/* Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

#include <unistd.h>
#include <stdio.h>

//verificar se a base valida
int	ft_is_valid(int chr, int len)
{
	int i = 0;
	char *base_upper = "0123456789ABCDEF";
	char *base_lower = "0123456789abcdef";

	while (i < len)
	{
		if (chr == base_upper[i] || chr == base_lower[i])
			return (1);
		i++;
	}
	return (0);
}

//verificar se ha espacos
int	ft_is_space(char c)
{
	if (c <= 32)
		return 1;
	return 0;
}

//atoi base
int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0; sign = 1, res = 0;
	while (ft_is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && ft_is_valid(str, str_base))
	{
		res *= str_base;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			res += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 'a' + 10;
		i++;
	}
	return (res * sign);
}
 
