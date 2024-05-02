/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putudec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:59:40 by lude-bri          #+#    #+#             */
/*   Updated: 2024/05/02 18:52:19 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

int	ft_putudec(unsigned int n)
{
	long	a;
	char	c;
	int		count;

	a = n;
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
		count++;
	}
	return (count);
}
