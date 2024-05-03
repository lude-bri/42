# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lude-bri <lude-bri@42student.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 09:39:06 by lude-bri          #+#    #+#              #
#    Updated: 2024/05/03 10:27:16 by lude-bri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf 
NAME = libftprintf.a

SRCS_FILES = ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putptr.c \
	ft_putstr.c ft_putudec.c 
				
OBJS = $(SRCS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all

.PHONY : all clean fclean re
