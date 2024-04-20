# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:21:50 by lude-bri          #+#    #+#              #
#    Updated: 2024/04/20 08:55:44 by lude-bri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf 
NAME = libft.a 

SRCS = ft_isalpha.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlcat.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all

.PHONY : all clean fclean re
