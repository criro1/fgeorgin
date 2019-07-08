# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: forange- <forange-@student.fr.42>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 23:08:59 by kirill            #+#    #+#              #
#    Updated: 2019/07/08 16:54:19 by forange-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

LDFLAGS=-L./libft

LDLIBS=-lft

SRC=valid_fillit.c map_generator.c solver.c ft_if_first_ok.c

all: $(NAME)

$(NAME): $(SRC) fillit.h
	make -C ./libft
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) $(LDLIBS) -I./libft -o $(NAME)

clean:
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: clean fclean all re
