/*Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/
#include <stdio.h>
#include <stdlib.h>

/*	Display prime factors of a number.
 *
 *	If 'n' is one print 1.
 *	Loop from n = 2 to 'nbr' while 'n' is smaller than 'nbr'
 *		If 'nbr' is divisible by 'n'
 *			Print 'n'.
 *			If 'nbr' is equal to 'n'
 *				Break out of loop.
 *			Print '*'
 *			Divide 'nbr' by 'n'
 *			Set n back to 2.
 *	Print newline.
 *	*/

int main(int argc, char *argv[])
{
	int nbr;
	int n;

	if (argc == 2)
	{
		nbr = atoi(argv[1]);
		if (nbr == 1)
			printf("1");
		n = 2;
		while (nbr >= n)
		{
			if ((nbr % n) == 0)
			{
				printf("%d", n);
				if (nbr == n)
					break;
				printf("*");
				nbr /= n;
				n = 2;
			}
			++n;
		}
	}
	printf("\n");
	return 0;
}
