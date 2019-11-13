# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 20:23:18 by fgeorgin          #+#    #+#              #
#    Updated: 2019/11/13 20:25:34 by fgeorgin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

NAME1 = checker

HEADER = push_swap.h

all:
    gcc push_swap.c operations.c make_list.c ft_printf/libftprintf.a -I $(HEADER) -o $(NAME)
	gcc checker.c operations.c make_list.c ft_printf/libftprintf.a -I $(HEADER) -o $(NAME1)

clean:
    /bin/rm -f $(OBJ)

fclean: clean
    /bin/rm -f $(NAME)

re: fclean all
