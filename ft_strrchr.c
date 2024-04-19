/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:07:39 by lude-bri          #+#    #+#             */
/*   Updated: 2024/04/18 08:33:15 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	//anunciar variaveis
	int	i;
	char	cc;
	char	*a;

	//anunciar valores
	i = 0;
	cc = (char)c;
	a = NULL;
	//loop pela string
	while (s[i])
	{
		if (s[i] == cc)
			a = (char *) &s[i];
		i++;
	}
	//checar se o carac for nulo
	if (s[i] == cc)
		a = (char *) &s[i];
	// se nao encontrarmos o char, retorne nulo
	return (a);
}

// int	main(void)
// {
// 	const char str[] = "reclaracao dos direitos humanos";
// 	const char ch = 'd';
// 	const char	*ret;

// 	ret = ft_strrchr(str, ch);
// 	printf("String depois da |%c| e - |%s|\n", ch, ret);
// 	return (0);
// }