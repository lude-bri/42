/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:59:28 by lude-bri          #+#    #+#             */
/*   Updated: 2024/04/18 12:13:26 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*a;

	i = 0;
	if (!dest && !src)
		return (0);
	a = (unsigned char *)src;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)a)[i];
		i++;
	}
	return (dest);
}
