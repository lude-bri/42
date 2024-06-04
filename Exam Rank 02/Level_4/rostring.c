/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

//escrever um programa onde a primeira palavra vai ser a ultima
#include <unistd.h>

int ft_isspace(char c)
{
	return ((c == ' ') || (c == '\t'));
}

int main (int ac, char **av)
{
	char *str;
	int word_start;
	int word_end;
	int space_found;
	int c;

	if (ac >= 2)
	{
		str = av[1];
		c = 0;
		while (ft_isspace(str[c]))
			c++;
		word_start = c;
		while (str[c] && !ft_isspace(str[c]))
			c++;
		word_end = c;
		while (ft_isspace(str[c]))
			c++;
		while (str[c])
		{
			while (ft_isspace(str[c]) && ft_isspace(str[c + 1]))
				c++;
			if (ft_isspace(str[c]))
				space_found = 1;
			write (1, &str[c++], 1);
		}
		if (space_found)
			write (1, " ", 1);
		while (word_start < word_end)
			write (1, &str[word_start++], 1);
	}
	write (1, "\n", 1);
	return (0);
}

