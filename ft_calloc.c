/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:18:25 by lude-bri          #+#    #+#             */
/*   Updated: 2024/04/20 09:29:12 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char		*tmp;

	tmp = malloc(sizeof(nmemb * size));
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, sizeof(nmemb * size));
	return (tmp);
}
