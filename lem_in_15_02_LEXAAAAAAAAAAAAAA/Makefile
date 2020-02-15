# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 20:59:45 by fgeorgin          #+#    #+#              #
#    Updated: 2019/11/18 17:11:34 by fgeorgin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

HEADER = lem_in.h

LIBFT = ./libft/libft.a

SRC = ft_ants_to_ways.c ft_bfs.c ft_do_ways_diff.c ft_free_and_malloc.c \
ft_if_n_ways.c ft_move_sh_w.c main.c valid_1.c valid_2.c validation.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(OBJ) $(NAME)

$(LIBFT):
	make -C ./libft

$(OBJ): %.o : %.c
	gcc -g -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	gcc -g -Wall -Wextra -Werror $(OBJ) $(LIBFT) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all