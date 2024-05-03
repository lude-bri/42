/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:07:16 by lude-bri          #+#    #+#             */
/*   Updated: 2024/05/03 12:08:15 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexlong(unsigned long n);

int	ft_putptr(unsigned long n)
{
	int	count;

	count = 0;
	if (!n)
		return (write(1, "(nil)", 5));
	write (1, "0x", 2);
	count += ft_puthexlong(n);
	return (count + 2);
}

int	ft_puthexlong(unsigned long n)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_puthexlong(n / 16);
		count += ft_puthexlong(n % 16);
	}
	else
	{
		count += ft_putchar(base[n]);
	}
	return (count);
}
