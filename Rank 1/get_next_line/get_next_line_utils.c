/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:10:04 by lude-bri          #+#    #+#             */
/*   Updated: 2024/05/15 10:35:20 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
char		*ft_substr(char *s, unsigned int start, size_t len);

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*sptr;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	sptr = (char *)s1;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	if (sptr)
		free(sptr);
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*tmp;

	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, (nmemb * size));
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char)c;
	while (s[i])
	{
		if (s[i] != cc)
			i++;
		else
			return ((char *) &s[i]);
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	size_t			x;
	unsigned char	*a;

	i = 0;
	x = '\0';
	a = (unsigned char *)s;
	while (i < n)
	{
		a[i] = x;
		i++;
	}
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*str;

	i = 0;
	if (!*s)
		return (0);
	str = (char *)s;
	if (start > ft_strlen(s))
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	//free (s);
	str[i] = 0;
	return ((char *)str);
}
