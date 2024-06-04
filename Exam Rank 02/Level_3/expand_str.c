/*
 Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>
 */

//Escrever um programa que pega uma string e escreve exatamente 3 espacos entre cada palavra

#include <unistd.h>

int	ft_is_space(char c)
{
	if (c <= 32)
		return 1;
	return 0;
}
int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0, space = 0;
		while (ft_is_space(av[1][i]))
			i++;
		while (av[1][i])
		{
			if (ft_is_space(av[1][i]))
				space = 1;
			if (!ft_is_space(av[1][i]))
			{
				if (space)
					write (1, "   ", 3);
				space = 0;
				write (1, &av[1][i], 1);
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
