/*
 * Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/

#include "list.h"

/*	While the next node exists
 *		Compare lst->data with next->data
 *			If the value in lst->data is greater than
 *			the value in next->next->data
 *				Swap the values
 *				Set lst to the beginning
 *			else
 *				Go to the next node
 *	*/

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*lst_start;
	int		to_swap;

	if (!lst)
		return (0);
	lst_start = lst;
	while (lst->next)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			to_swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = to_swap;
			lst = lst_start;
		}
		else
			lst = lst->next;
	}
	lst = lst_start;
	return (lst);
}

