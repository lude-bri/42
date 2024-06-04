/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <stdio.h>
#include <unistd.h>


//Escrever um programa que pega um numero e soma com os primos iguais ou menores que ele

//funcao de char para int(atoi)
int	ft_atoi(char *str)
{
	int i = 0, sign = 1, res = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}
//funcao para verificar primo
int	is_prime(int n)
{
	int check = 2;
	if (n <= 1)
		return (0);
	while (check < n)
	{
		if (n % check == 0)
			return (0);
		check++;
	}
	return (1);
}


//funcao para colocar numeros
void put_nbr(int n)
{
	char	digit;
	if (n >= 10)
		put_nbr(n / 10);
	digit = n % 10 + '0';
	write (1, &digit, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int nbr; //numero
		int sum; //soma
		
		nbr = ft_atoi(av[1]);
		sum = 0;
		while (nbr > 0)
		{
			if (is_prime(nbr))
					sum += nbr;
			nbr--;
		}
		put_nbr(sum);
	}
	else if (ac != 2)
		write (1, "0\n", 2);
	return (0);
}
