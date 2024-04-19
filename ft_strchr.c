/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:05:25 by lude-bri          #+#    #+#             */
/*   Updated: 2024/04/17 11:04:23 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	//anunciar variaveis
	int	i;
	char	cc;

	//anunciar valores
	i = 0;
	cc = (char)c;
	//loop pela string
	while (s[i])
	{
		//verificar se e o char que queremos
		if (s[i] != cc)
			i++;
		else
			return ((char *) &s[i]);
	}
	//checar se o carac for nulo
	if (s[i] == cc)
		return ((char *) &s[i]);
	// se nao encontrarmos o char, retorne nulo
	else
		return (NULL);
}

// int	main(void)
// {
// 	const char str[] = "reclaracao dos direitos humanos";
// 	const char ch = 'd';
// 	const char	*ret;

// 	ret = ft_strchr(str, ch);
// 	printf("String depois da |%c| e - |%s|\n", ch, ret);
// 	return (0);
// }