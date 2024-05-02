/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:11:29 by lude-bri          #+#    #+#             */
/*   Updated: 2024/05/01 19:12:59 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

int	f_specifiers(char *str, va_list a);

int	ft_printf(const char *s, ...)
{
	int				return_value;
	int				i;
	va_list			args;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	va_start(args, s);
	while (str[i])
	{
		if (str[i] == '%' && str[i])
			f_specifiers(str[i + 1], args);
		while (str[i] && str[i] != '%')
			write (1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (return_value);
}

int	f_specifiers(char *str, va_list a)
{
	if(*str == 'c')
		ft_putchar_fd(va_arg(a, int));//printa um single char;
	else if(*str == 's')
		//printa uma string;
	else if(*str == 'p')
		//o void * pointer argument printa em hexadecimal
	else if(*str == 'd')
		//printa um numero decimal (base 10)
	else if(*str == 'i')
		//printa um integer na base 10
	else if(*str == 'u')
		//printa um numero unsigned decimal base 10
	else if(*str == 'x')
		//printa um numero em hexadecimal lowercase
	else if(*str == 'X')
		//printa um numero em hexadecimal uppercase
	else if(*str == '%')
		write (1, '%', 1); //printa um sinal de porcentagem
	return (0);
}

int main(void)
{
	//ft_printf("%c", "c");
	printf("%c", "c");
	return (0);
}
