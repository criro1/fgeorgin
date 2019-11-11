# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 12:40:58 by fgeorgin          #+#    #+#              #
#    Updated: 2019/04/15 16:10:51 by fgeorgin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ./includes/

SOURCE = srcs/ft_putchar.c \
		 srcs/ft_putstr.c \
		 srcs/ft_strcmp.c \
		 srcs/ft_strlen.c \
		 srcs/ft_swap.c

OBJECTS = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c -I $(HEADER) $(SOURCE)
		ar rc $(NAME) $(OBJECTS)

clean:
		/bin/rm -f $(OBJECTS)
fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
