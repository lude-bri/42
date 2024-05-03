/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:46:16 by lude-bri          #+#    #+#             */
/*   Updated: 2024/05/03 12:04:29 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	c;
	int		count;

	c = n;
	count = 0;
	if (c < 0)
	{
		write(1, "-", 1);
		count += 1;
		c = c * -1;
	}
	if (c > 9)
	{
		count += ft_putnbr(c / 10);
		c = c % 10;
	}
	if (c <= 9)
		count += ft_putchar(c + 48);
	return (count);
}
