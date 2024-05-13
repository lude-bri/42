/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:00:03 by lude-bri          #+#    #+#             */
/*   Updated: 2024/05/13 09:22:10 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//1. ler a primeira string definida pelo buffer para dentro de uma variavel;
	//1.1. verificacoes de nulidade;
	//1.2. preciso botar a info. do meu txt na minha nova variavel (raw_line);
//2. storage da string da variavel (def pelo n.de chars ate \n);
//3. podar a variavel;
//4. guardar o pointer para a ultima posicao do \n;
//5. retornar a nova linha;

char	*fill_line(int fd, char *str);
char	*line_to_clean(char *str, char *rubbish);
char	*ft_rub(char *str_line, char *str_rub);


char	*get_next_line(int fd)
{
	char				*raw_line;
	char				*new_line;
	static char			*ptr_to_last;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!ptr_to_last)
		ptr_to_last = ft_calloc(1,1);
	raw_line = fill_line(fd, ptr_to_last);
	if(!raw_line)
		return (NULL);
	new_line = line_to_clean(raw_line, ptr_to_last);
	if (!new_line)
		return (0);
	ptr_to_last = ft_rub(raw_line, ptr_to_last);
	free(raw_line);
	return (new_line);
}

/*funcao para preencher a linha raw*/
char	*fill_line(int fd, char *str)
{
	char		*line_to_read;
	char		*buffer;
	char		*rubbish;
	size_t		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line_to_read = ft_calloc(1,1);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[bytes_read] = '\0';
		line_to_read = ft_strjoin(line_to_read, buffer); //verificar leaks - preciso free
		if (!line_to_read)
			return (0);
	}
	free(buffer);
	if (!str)
		return (ft_strdup(""));
	rubbish = str;
	line_to_read = ft_strjoin(rubbish, line_to_read);
	return (line_to_read);
}

/*funcao para limpar a raw_line*/
char	*line_to_clean(char *str, char *rubbish)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else if (str[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	line = ft_substr(str, 0, (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		line[i + 1] = '\0';
	return (line);
}

/*funcao para recolher o lixo*/
char	*ft_rub(char *str_line, char *str_rub)
{
	int	i;

	i = ft_strlen(str_line);
	str_rub = malloc(sizeof(char) * (i + 1));
	if (!str_rub)
	{
		free(str_rub);
		return (0);
	}
	i = 0;
	while (str_line[i] && str_line[i] != '\n')
		i++;
	if (str_line[i] == '\n')
		str_rub = ft_substr(str_line, i + 1, ft_strlen(str_line) - i);
	else
		str_rub = ft_substr(str_line, i, ft_strlen(str_line) - i);
	return (str_rub);
}

int	main(void)
{
	int			fd;
	const char	*path;
	char		*a;

	path = "shrek.txt";
	fd = open(path, O_RDONLY);
	a = get_next_line(fd);
	printf("First line : %s", a);
	a = get_next_line(fd);
	printf("Second line : %s", a);
	a = get_next_line(fd);
	printf("Third line : %s", a);
	a = get_next_line(fd);
	printf("Fourth line : %s", a);
	a = get_next_line(fd);
	printf("Fifth line : %s", a);
	a = get_next_line(fd);
	printf("Sixth line : %s", a);
	return (0);
}

