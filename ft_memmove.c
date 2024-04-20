/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:59:28 by lude-bri          #+#    #+#             */
/*   Updated: 2024/04/20 19:51:13 by lude-bri         ###   ########.fr       */
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

/*int	main(void)
{
 	char dst1[0xF0];
 	char dst2[0xF0];
 	char *data = "thi\xc3\x9f \xc3\x9f\xde\xad\xbe\xeftri\xc3\xb1g will be \xc3\xb8v\xc3\xa9rlap\xc3\xa9d !\r\n";
 	int size = 0xF0 - 0xF;

 	printf("%s\n", (char *)memmove(dst1 + 3, dst1, size));
 	printf("%s\n", (char *)ft_memmove(dst2 + 3, dst2, size));

	return (0);
}*/
