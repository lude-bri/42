/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

#include <unistd.h>
#include <stdio.h>


int is_power_of_2(unsigned int n)
{
    int i = 1;
    while (i <= n)
    {
        if (i == n)
            return (1);
        i *= 2;
    }
    return (0);
}

int	main(void)
{
	printf("%d\n", is_power_of_2(0));
	printf("%d\n", is_power_of_2(2));
	printf("%d\n", is_power_of_2(4));
	printf("%d\n", is_power_of_2(6));
	printf("%d\n", is_power_of_2(8));
	printf("%d\n", is_power_of_2(32));
	printf("%d\n", is_power_of_2(42));
	printf("%d\n", is_power_of_2(67));
	printf("%d\n", is_power_of_2(124));
	printf("%d\n", is_power_of_2(256));
	return (0);
}
