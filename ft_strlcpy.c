/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:39:35 by lude-bri          #+#    #+#             */
/*   Updated: 2024/04/20 19:51:16 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (size <= 0)
		return (ft_strlen(src));
	while ((i < size - 1) && (src[i]))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char	dest[] = "x";
// 	char	src[] = "lorem";
// 	printf("%zu\n", ft_strlcpy(dest, src, 15));
// 	printf("%d\n", strlcpy(dest, src, 15));
// 	return (0);
// }