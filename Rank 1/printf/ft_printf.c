/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:11:29 by lude-bri          #+#    #+#             */
/*   Updated: 2024/05/03 12:17:48 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	f_specifiers(char str, va_list a);

int	ft_printf(const char *s, ...)
{
	int				result;
	int				i;
	va_list			args;
	unsigned char	*str;

	i = 0;
	result = 0;
	str = (unsigned char *)s;
	va_start(args, s);
	while (str[i])
	{
		if (str[i] == '%' && str[i])
		{
			result += f_specifiers(str[i + 1], args);
			i++;
		}
		else if (str[i] != '%' && str[i])
			result += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (result);
}

static int	f_specifiers(char str, va_list a)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(a, int));
	else if (str == 's')
		count += ft_putstr(va_arg(a, char *));
	else if (str == 'p')
		count += ft_putptr(va_arg(a, unsigned long));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(a, int));
	else if (str == 'u')
		count += ft_putudec(va_arg(a, int));
	else if (str == 'x' || str == 'X')
		count += ft_puthex(str, va_arg(a, unsigned int));
	else if (str == '%')
		count += ft_putchar('%');
	return (count);
}
// int	main(void)
// {
// 	char c = 'k'; // %c
// 	char *str = "String test"; // %s
// 	char *var; var = &c;// %p
// 	int	nbr = -5;// %d // %i
// 	unsigned int nbrr = 20;// %u
// 	int b= 0xffffffff;// %x // %X
// 	// %%
// 	int i;
// 	printf("Printf replica:\n");
// 	i = ft_printf("| TEST TEXT |\n| Single Char: %c |\n| String: %s |\n| \
// 		Pointer Adress: %p |\n| Decimal: %d |\n| Integer %i |\n| \
// 		Unsign deci: %u |\n| HexLower: %x |\n| HexUpper: %X |\n| \
// 		Percentage sign: %% |\n", c, str, var, nbr, nbr, nbrr, b, b);
// 	printf("\nReturn Value: %d", i);
// 	///////////////////////////////
// 	printf("\nPrintf original:\n");
// 	i = printf("| TEST TEXT |\n| Single Char: %c |\n| String: %s |\n| \
// 		Pointer Adress: %p |\n| Decimal: %d |\n| Integer %i |\n| \
// 		Unsign deci: %u |\n| HexLower: %x |\n| HexUpper: %X |\n| \
// 		Percentage sign: %% |\n", c, str, var, nbr, nbr, nbrr, b, b);
// 	printf("\nReturn Value: %d", i);
// 	return (0);
// }