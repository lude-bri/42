/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:03:48 by lude-bri          #+#    #+#             */
/*   Updated: 2024/04/18 13:02:43 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	//anunciar variaveis
	size_t	i; //index para s1

	//valor das variaveis
	i = 0;

	//loop para verificar se sao iguais
	while((s1[i] && s2[i]) || n > i)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]); //se diferente, retorne diferenca
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	const char	str1[] = "Rap";
// 	const char	str2[] = "Rarida";

// 	printf("%d\n", ft_strncmp(str1, str2, 3));
// 	return (0);
// }