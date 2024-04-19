/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:05:44 by lude-bri          #+#    #+#             */
/*   Updated: 2024/04/18 13:25:08 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	//variaveis
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	
	//checar se o little esta vazio
	if (!little[j])
		return ((unsigned char *)big);
	//loop no big
	while (big[i] && i < len)
	{
		//verificar se temos o little pequeno dentro do big
		while (big[i] && little[j])
		{
			
		}
	}
}