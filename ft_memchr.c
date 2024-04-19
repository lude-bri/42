/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:51:44 by lude-bri          #+#    #+#             */
/*   Updated: 2024/04/18 12:35:22 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	//variaveis e valores
	size_t  i;
	unsigned char *re;

	i = 0;
	re = (unsigned char *)s;
	//loop para saber se existe o c em s
	while(re[i] || i < n)
	{
		if (re[i] == (unsigned char)c)
			return ((unsigned char *) &re[i]);
		i++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	char	str[] = "retangulo";
// 	char	c = 'e';
	
// 	printf("%s\n", (const char *)ft_memchr(str, c, 4));
// 	return (0);
// }