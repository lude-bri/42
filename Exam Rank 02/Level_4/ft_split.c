/**
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdlib.h>

char	ft_strncpy(char *s1, char *s2, int n)
{
	int i = 0;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = NULL;
	return (s1);
}

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c =='\n')
		return (1);
	return (0);
}

char	**ft_split(char *str)
{
	int i = 0; //index 1
	int j = 0; //index 2
	int k = 0; //index 3
	int w = 0; //word count

	//verificar palavras
	while (str[i])
	{
		while (str[i] && ft_is_space(str[i]))
				i++;
		if(str[i])
			w++;
		while (str[i] && !ft_is_space(str[i]))
			i++;
	}
	//alocar memoria para nova string
	char **out = (char **)malloc(sizeof(char *) * (w + 1));
	
	//ver palavra por palavra
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_is_space(str[i]))
			i++;
		j = i;
		while (str[i] && !ft_is_space(str[i]))
			i++;
		if (i > j)
		{
			//alocar espaco para palavra e preencher 
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
		out[k] = NULL;
		return (out);
	}
}
