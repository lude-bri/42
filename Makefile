# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:21:50 by lude-bri          #+#    #+#              #
#    Updated: 2024/04/18 12:38:44 by lude-bri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a #nome da biblioteca / .a is a libraru containing object modules
CC = cc #compilador
CFLAGS = -Wall -Wextra -Werror #flags
RM = rm -rf #remove

#source files
SRCS = ft_isalpha.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlcat.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c


#objects sao sourcefiles.o que existem a partir de sourcefiles.c 
OBJS =  $(SRCS:.c=.o)

#quando make all - executa minha biblioteca
all: $(NAME)

#bilbioteca depende da existencia dos objetos (.o), usando comando ar para criar a lib
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all

.PHONY : all clean fclean re
