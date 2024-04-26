/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:06:45 by lude-bri          #+#    #+#             */
/*   Updated: 2024/04/26 12:30:45 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if(!node)
		return (0);
	node->content = content;
	node->next = 0;

	return(node);
}

int main(void)
{
	char	str[] = "morango";
	printf("%s\n", (char *)ft_lstnew((char *)str));
	return (0);
}
