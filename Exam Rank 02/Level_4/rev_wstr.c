/* Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/

#include <unistd.h>

/*	Print words in string in reverse order
 *
 *	Get the 'len' of input 'str';
 *	Loop through 'str' from the end;
 *		Skip spaces and the NULL character;
 *		Save 'word_end';
 *		Skip non-space characters;
 *		Save 'word_start';
 *		Set 'str_idx' to 'word_start';
 *		Print 'word_start' to 'word_end';
 *		If str_idx is not 0
 *			Print ' '
 *	Print '\n'
 *	Return
 *
 */

int	ft_isspace(char c)
{
	if ((c == ' ') || (c == '\t'))
		return (1);
	return (0);
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	char	*str;
	int		word_start;
	int		word_end;
	int		len;
	int		str_idx;

	if (argc == 2)
	{
		str = argv[1];
		len = ft_strlen(str);
		while (len >= 0)
		{
			while (!str[len] || ft_isspace(str[len]))
				--len;
			word_end = len;
			while (str[len] && !ft_isspace(str[len]))
				--len;
			word_start = (len + 1);
			str_idx = word_start;
			while (word_start <= word_end)
				write(1, &str[word_start++], 1);
			if (str_idx != 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}

