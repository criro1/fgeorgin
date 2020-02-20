# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ediego <ediego@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 20:59:45 by fgeorgin          #+#    #+#              #
#    Updated: 2020/02/18 20:23:35 by ediego           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

NAME_V = visual

HEADER = lem_in.h

LIBFT = ./libft/libft.a

SRC = ft_ants_to_ways.c ft_bfs.c ft_do_ways_diff.c ft_free_and_malloc.c \
ft_if_n_ways.c ft_move_sh_w.c main.c valid_1.c valid_2.c validation.c \
ft_exit_func.c

#SRC_V = ft_bfs.c ft_if_n_ways.c ft_move_sh_w.c valid_1.c valid_2.c validation.c \
ft_exit_func.c vs_visual.c vs_scene.c vs_scene2.c vs_scene3.c vs_scene4.c vs_key.c vs_read_input.c

OBJ = $(SRC:.c=.o)

OBJ_V = $(SRC_V:.c=.o)

all: $(NAME) #$(NAME_V)

$(LIBFT):
	make -C ./libft

$(OBJ): %.o : %.c
	gcc -g -Wall -Wextra -Werror -c $< -o $@

$(OBJ_V): %.o : %.c
	gcc -g -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	@echo "\033[32mCompiling ./lem-in\033[0m"
	@gcc -g -Wall -Wextra -Werror $(OBJ) $(LIBFT) -o $(NAME)

#$(NAME_V): $(LIBFT) $(OBJ_V)
#	@echo "\033[31mCompiling ./visual\033[0m"
#	@gcc -g -Wall -Wextra -Werror $(LIBFT) -lmlx -framework OpenGL -framework Appkit $(OBJ_V) -o $(NAME_V)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(OBJ_V)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
#	rm -rf $(NAME_V)
	make fclean -C ./libft

re: fclean all