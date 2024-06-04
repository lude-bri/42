/*
 * Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int i = 0;
	int len;
	int *range;

	len = abs(end - start) + 1;
	range = malloc(sizeof(int) * len);
	if (!range)
		return NULL;
	while (i < len)
	{
		if (start < end)
			range[i] = start++;
		else
			range[i] = start--;
		i++;
	}
	return (range);
}

int abs(int n)
{
	//explicacao
	// condicao ? valor_se_verdadeiro : valor_se_falso
	return ((n < 0) ? -n : n);

}

int	main(void)
{
	int	*tab;
	int	idx;
	int	start;
	int	end;
	int	size;

	idx = 0;
	start = -5;
	end = 5;
	tab = ft_range(start, end);
	size = abs(end - start) + 1;
	while (idx < size)
	{
		printf(" [%i] ", tab[idx]);
		idx++;
	}
	printf("\n");
}
