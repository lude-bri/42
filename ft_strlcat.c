/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:14:58 by lude-bri          #+#    #+#             */
/*   Updated: 2024/04/17 09:48:43 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	//acrescenta meu contador i ate chegar no limite do buffer
	while (i < size && dst[i])
		i++;
	
	//fazer o cat a partir do ponto onde o contador i + 0 + nulo sendo menor que o buffer
	while ((i + j + 1) < size && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	//se o i for diferente do size do buffer, acrescenta o nulo.
	if (i != size)
		dst[i + j] = '\0';
	return (i + strlen(src));
}

// int	main(void)
// {
// 	char	d[] = "Ola ";
// 	char	s[] = "Mundo";
// 	int		n = strlen(d); 
// 	printf("%zu\n", ft_strlcat(d, s, n));
// 	return (0);
// }