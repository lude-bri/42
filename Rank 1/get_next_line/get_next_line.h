/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:06:42 by lude-bri          #+#    #+#             */
/*   Updated: 2024/05/15 09:28:36 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(const char *s1, const char *s2);
//char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
char	*fill_line(int fd, char *str);
char	*line_to_clean(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif
