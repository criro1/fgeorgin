# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: forange- <forange-@student.fr.42>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 23:08:59 by kirill            #+#    #+#              #
#    Updated: 2019/07/08 17:46:30 by forange-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

LDFLAGS=-L./libft

LDLIBS=-lft

SRC=valid_fillit.c map_generator.c solver.c ft_if_first_ok.c

all: libmake $(NAME)

$(NAME): $(SRC) fillit.h
	@$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) $(LDLIBS) -I./libft -o $(NAME)

clean:
	$(MAKE) -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: clean fclean all re libmake
