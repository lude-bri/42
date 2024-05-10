/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:00:03 by lude-bri          #+#    #+#             */
/*   Updated: 2024/05/10 18:16:06 by lude-bri         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char			*raw_line;
	char			*new_line;
	static char		*ptr_to_last;

	if (!fd || !BUFFER_SIZE)
		return (0);
	raw_line = fill_line(fd); /*funcao que faz o storage ate identificar \n*/
	if(!raw_line)
		return (NULL);
	/*loop para podar raw_line e preencher a new_line*/
	while (raw_line)
	{
		/*podar a variavel*/
		new_line = line_to_clean(raw_line);
		if (!new_line)
		{
			/*clean-free*/
		}
	}
	/*retornar o pointer ate a \n + 1 (inicio da proxima linha)*/
	ptr_to_last = ft_strrchr(raw_line, '\n');
	return (new_line);
}

/*funcao para preencher a linha raw*/
char	*fill_line(int fd)
{
	char		*line_to_read;
	char		*buffer;
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
	return (line_to_read);
}

/*funcao para limpar a raw_line*/
char	*line_to_clean(char *str);
{
	//podar a raw_line;

	char	*str_clean;
	char	*s;
	int		len;

	i = 0;
	if (!str)
		return (0);
	s = ft_strchr(str, '\n'); //buscar onde ele acha o \n
	len = ft_strlen(s); //ver o tamanho da string ate o \n
	str_clean = ft_substr(str, 0, len); //fazer uma string clean
	if (!str_clean)
		return (0);
	while (str[i])
	{
		if (str_to_clean[i] != '\n')
		i++;
	}
	if (str[i] == '\n')
		return ()

}

int	main(void)
{
	int			fd;
	const char	*path;
	char		*a;

	path = "shrek.txt";
	fd = open(path, O_RDONLY);
	a = get_next_line(fd);
	printf("%s\n", a);
	return (0);
}

