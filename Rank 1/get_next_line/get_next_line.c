/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:00:03 by lude-bri          #+#    #+#             */
/*   Updated: 2024/05/15 10:53:36 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(int fd, char *str);
char	*line_to_clean(char *str);
char	*ft_rub(char *str_line, char *str_rub);
size_t	ft_strlen(const char *s);

char	*get_next_line(int fd)
{
	char				*raw_line;
	char				*new_line;
	static char			*ptr_to_last;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	if (!ptr_to_last)
		ptr_to_last = ft_calloc(1, 1);
	raw_line = fill_line(fd, ptr_to_last);
	if (!raw_line)
		return (NULL);
	new_line = line_to_clean(raw_line);
	if (!new_line)
		return (NULL);
	ptr_to_last = ft_rub(raw_line, ptr_to_last);
	//if (!ptr_to_last)
	//	return (NULL);
	free(raw_line);
	return (new_line);
}

char	*fill_line(int fd, char *str_sta)
{
	char		*buffer;
	int			bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	bytes_read = 1;
	*buffer = '\0';
	while (bytes_read != 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			//if (str_sta)
			//free(str_sta);
			free(buffer);
			str_sta = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str_sta = ft_strjoin(str_sta, buffer);
	}
	free(buffer);
	return (str_sta);
}

char *line_to_clean(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2)); //verificar leaks
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_rub(char *str_line, char *str_rub)
{
	int	i;

	i = ft_strlen(str_line);
//	str_rub = malloc(sizeof(char) * (i + 1)); //verificar leaks
	if (!str_rub)
	{
		free(str_line);
		return (0);
	}
	i = 0;
	while (str_line[i] && str_line[i] != '\n')
		i++;
	//if (str_line[i] == '\n')
	str_rub = ft_substr(str_line, i + 1, ft_strlen(str_line) - i);
	//else
	//	str_rub = ft_substr(str_line, i, ft_strlen(str_line) - i);
	return (str_rub);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	int			fd;
	const char	*path;
	char		*a;

	path = "alpha.txt";
	fd = open(path, O_RDONLY);
	a = get_next_line(fd);
	printf("First line : %s", a);
	a = get_next_line(fd);
	printf("Second line : %s", a);
	a = get_next_line(fd);
	return (0);
}
*/
