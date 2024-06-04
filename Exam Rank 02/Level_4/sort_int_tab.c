/*Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	n;
	int				to_swap;

	n = 0;
	while (n < (size - 1))
	{
		if (tab[n] > tab[n + 1])
		{
			to_swap = tab[n];
			tab[n] = tab[n + 1];
			tab[n + 1] = to_swap;
			n = 0;
		}
		else
			++n;
	}
}
